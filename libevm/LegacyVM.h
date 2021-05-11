// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2014-2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#pragma once

#include "Instruction.h"
#include "LegacyVMConfig.h"
#include "VMFace.h"

#include <immintrin.h>
//#include <mmintrin.h> // mmx
//#include <xmmintrin.h> // sse
//#include <emmintrin.h> // sse2

namespace dev
{
namespace eth
{

class LegacyVM: public VMFace
{
public:
    virtual owning_bytes_ref exec(u256& _io_gas, ExtVMFace& _ext, OnOpFunc const& _onOp) override final;

#if EIP_615
    // invalid code will throw an exeption
    void validate(ExtVMFace& _ext);
    void validateSubroutine(uint64_t _PC, uint64_t* _rp, u256* _sp);
#endif

    bytes const& memory() const { return m_mem; }
    u256s stack() const {
        u256s stack(m_SP, m_stackEnd);
        reverse(stack.begin(), stack.end());
        return stack;
    };

private:

    u256* m_io_gas_p = 0;
    uint64_t m_io_gas = 0;
    ExtVMFace* m_ext = 0;
    OnOpFunc m_onOp;

    static std::array<InstructionMetric, 256> c_metrics;
    static void initMetrics();
    static u256 exp256(u256 _base, u256 _exponent);
    void copyCode(int);
    typedef void (LegacyVM::*MemFnPtr)();
    MemFnPtr m_bounce = 0;
    MemFnPtr m_onFail = 0;
    uint64_t m_nSteps = 0;
    EVMSchedule const* m_schedule = nullptr;

    // return bytes
    owning_bytes_ref m_output;

    // space for memory
    bytes m_mem;

    // space for code
    bytes m_code;

    /// RETURNDATA buffer for memory returned from direct subcalls.
    bytes m_returnData;

    // space for data stack, grows towards smaller addresses from the end
    u256 m_stack[1024];
    u256 *m_stackEnd = &m_stack[1024];
    size_t stackSize() { return m_stackEnd - m_SP; }
    
#if EIP_615
    // space for return stack
    uint64_t m_return[1024];
    
    // mark PCs with frame size to detect cycles and stack mismatch
    std::vector<size_t> m_frameSize;
#endif

    // constant pool
    std::vector<u256> m_pool;

    // interpreter state
    Instruction m_OP;                   // current operation
    uint64_t    m_PC    = 0;            // program counter
    u256*       m_SP    = m_stackEnd;   // stack pointer
    u256*       m_SPP   = m_SP;         // stack pointer prime (next SP)
#if EIP_615
    uint64_t*   m_RP    = m_return - 1; // return pointer
#endif

    // metering and memory state
    uint64_t m_runGas = 0;
    uint64_t m_newMemSize = 0;
    uint64_t m_copyMemSize = 0;

    // initialize interpreter
    void initEntry();
    void optimize();

    // interpreter loop & switch
    void interpretCases();

    // interpreter cases that call out
    void caseCreate();
    bool caseCallSetup(CallParameters*, bytesRef& o_output);
    void caseCall();

    void copyDataToMemory(bytesConstRef _data, u256*_sp);
    uint64_t memNeed(u256 const& _offset, u256 const& _size);

    void throwOutOfGas();
    void throwBadInstruction();
    void throwBadJumpDestination();
    void throwBadStack(unsigned _removed, unsigned _added);
    void throwRevertInstruction(owning_bytes_ref&& _output);
    void throwDisallowedStateChange();
    void throwBufferOverrun(bigint const& _enfOfAccess);

    std::vector<uint64_t> m_beginSubs;
    std::vector<uint64_t> m_jumpDests;
    int64_t verifyJumpDest(u256 const& _dest, bool _throw = true);

    void onOperation() { onOperation(m_OP); }
    void onOperation(Instruction _instr);
    void adjustStack(unsigned _removed, unsigned _added);
    uint64_t gasForMem(u512 const& _size);
    void updateSSGas();
    void updateSSGasPreEIP1283(u256 const& _currentValue, u256 const& _newValue);
    void updateSSGasEIP1283(u256 const& _currentValue, u256 const& _newValue);
    void updateIOGas();
    void updateGas();
    void updateMem(uint64_t _newMem);
    void logGasMem();
    void fetchInstruction();
    
    uint64_t decodeJumpDest(const byte* const _code, uint64_t& _pc);
    uint64_t decodeJumpvDest(const byte* const _code, uint64_t& _pc, byte _voff);

    template<class T> uint64_t toInt63(T v)
    {
        // check for overflow
        if (v > 0x7FFFFFFFFFFFFFFF)
            throwOutOfGas();
        uint64_t w = uint64_t(v);
        return w;
    }
    
    template<class T> uint64_t toInt15(T v)
    {
        // check for overflow
        if (v > 0x7FFF)
            throwOutOfGas();
        uint64_t w = uint64_t(v);
        return w;
    }
    
    //
    // implementations of simd opcodes
    //
    // input bytes are the inline simd type descriptors for the operand vectors on the stack
    //
    enum class SimdType : uint8_t {
        Int2Lanes, // 2 int64_t on SSE register
        Int4Lanes, // 4 int32_t on SSE register
        Int8Lanes, // 8 int16_t on SSE register
        Int16Lanes, // 16 int8_t on SSE register
        Floating2Lanes, // 2 double on SSE register
        Floating4Lanes // 4 float on SSE register
    };
    void xadd    (SimdType);
    void xmul    (SimdType);
    void xsub    (SimdType);
    void xdiv    (SimdType);
    void xsdiv   (SimdType);
    void xmod    (SimdType);
    void xsmod   (SimdType);
    void xlt     (SimdType);
    void xslt    (SimdType);
    void xgt     (SimdType);
    void xsgt    (SimdType);
    void xeq     (SimdType);
    void xzero   (SimdType);
    void xand    (SimdType);
    void xoor    (SimdType);
    void xxor    (SimdType);
    void xnot    (SimdType);
    void xshr    (SimdType);
    void xsar    (SimdType);
    void xshl    (SimdType);
    void xrol    (SimdType);
    void xror    (SimdType);
    void xmload  (SimdType);
    void xmstore (SimdType);
    void xsload  (SimdType);
    void xsstore (SimdType);
    void xvtowide(SimdType);
    void xwidetov(SimdType);
    void xpush   (SimdType);
    void xput    (SimdType, SimdType);
    void xget    (SimdType, SimdType);
    void xswizzle(SimdType);
    void xshuffle(SimdType);
    
    u256 vtow(uint8_t _b, const u256& _in);
    void wtov(uint8_t _b, u256 _in, u256& _o_out);

    SimdType simdType()
    {
        uint8_t nt = m_code[++m_PC];  // advance PC and get simd type from code
        ++m_PC;                       // advance PC to next opcode, ready to continue
        return SimdType(nt);
    }

    __m128i _mm_mullo_epi8(__m128i a, __m128i b)
    {
        // unpack and multiply
        __m128i dst_even = _mm_mullo_epi16(a, b);
        __m128i dst_odd = _mm_mullo_epi16(_mm_srli_epi16(a, 8),_mm_srli_epi16(b, 8));
        // repack

        return _mm_or_si128(_mm_slli_epi16(dst_odd, 8), _mm_srli_epi16(_mm_slli_epi16(dst_even,8), 8));
    }

    inline __m128i _mm128_mullo_epi64(__m128i ab, __m128i cd)
    {
        /* ac = (ab & 0xFFFFFFFF) * (cd & 0xFFFFFFFF); */
        __m128i ac = _mm_mul_epu32(ab, cd);

        /* b = ab >> 32; */
        __m128i b = _mm_srli_epi64(ab, 32);

        /* bc = b * (cd & 0xFFFFFFFF); */
        __m128i bc = _mm_mul_epu32(b, cd);

        /* d = cd >> 32; */
        __m128i d = _mm_srli_epi64(cd, 32);

        /* ad = (ab & 0xFFFFFFFF) * d; */
        __m128i ad = _mm_mul_epu32(ab, d);

        /* high = bc + ad; */
        __m128i high = _mm_add_epi64(bc, ad);

        /* high <<= 32; */
        high = _mm_slli_epi64(high, 32);

        /* return ac + high; */
        return _mm_add_epi64(high, ac);
    }

    inline __m128i _mm_sll_epi8(__m128i a, __m128i b) {
        return _mm_and_si128(_mm_sll_epi16(a, b), _mm_set1_epi8(0xFFU << _mm_cvtsi128_si64(b)));
    }

    inline __m128i  _mm_srl_epi8(__m128i a, __m128i b) {
        return _mm_and_si128(_mm_srl_epi16(a, b), _mm_set1_epi8(0xFFU >> _mm_cvtsi128_si64(b)));
    }
};

}
}
