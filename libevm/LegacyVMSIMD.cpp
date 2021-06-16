#include "LegacyVM.h"
#include "../libsimdpp/simdpp/simd.h"

#if EIP_616

namespace dev {
namespace simd {
enum class OpType : unsigned char {
    Int,
    Floating
};
enum class LaneWidth : unsigned char {
    Bytes1,
    Bytes2,
    Bytes4,
    Bytes8
};
enum class LaneCount : unsigned char {
    Lanes2,
    Lanes4,
    Lanes8,
    Lanes16,
    Lanes32
};

class SIMDByte{
public:
    SIMDByte(uint8_t simdByte) : simdByte(simdByte){}

    OpType getOpType() const {
        return static_cast<OpType>(simdByte & 0b00000001);
    }
    LaneWidth getLaneWidth() const {
        return static_cast<LaneWidth>((simdByte & 0b00001100) >> 2);
    }
    LaneCount getLaneCount() const {
        return static_cast<LaneCount>((simdByte & 0b11100000) >> 5);
    }
private:
    uint8_t simdByte;
};
}
}

using namespace std;
using namespace simdpp;
using namespace dev;
using namespace dev::eth;
using namespace dev::simd;

void LegacyVM::xadd(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
    switch(simdByte.getLaneWidth()){
    case LaneWidth::Bytes1:
        uint8_t *vec_a = reinterpret_cast<uint8_t*>(m_SP);
        uint8_t *vec_b = reinterpret_cast<uint8_t*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            uint8<2> xmmA = load(vec_a);
            uint8<2> xmmB = load(vec_b);
            uint8<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            uint8<4> xmmA = load(vec_a);
            uint8<4> xmmB = load(vec_b);
            uint8<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes8:
            uint8<8> xmmA = load(vec_a);
            uint8<8> xmmB = load(vec_b);
            uint8<8> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes16:
            uint8<16> xmmA = load(vec_a);
            uint8<16> xmmB = load(vec_b);
            uint8<16> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes32:
            uint8<32> xmmA = load(vec_a);
            uint8<32> xmmB = load(vec_b);
            uint8<32> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    case LaneWidth::Bytes2:
        uint16_t *vec_a = reinterpret_cast<uint16_t*>(m_SP);
        uint16_t *vec_b = reinterpret_cast<uint16_t*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            uint16<2> xmmA = load(vec_a);
            uint16<2> xmmB = load(vec_b);
            uint16<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            uint16<4> xmmA = load(vec_a);
            uint16<4> xmmB = load(vec_b);
            uint16<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes8:
            uint16<8> xmmA = load(vec_a);
            uint16<8> xmmB = load(vec_b);
            uint16<8> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes16:
            uint16<16> xmmA = load(vec_a);
            uint16<16> xmmB = load(vec_b);
            uint16<16> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    case LaneWidth::Bytes4:
        uint32_t *vec_a = reinterpret_cast<uint32_t*>(m_SP);
        uint32_t *vec_b = reinterpret_cast<uint32_t*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            uint32<2> xmmA = load(vec_a);
            uint32<2> xmmB = load(vec_b);
            uint32<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            uint32<4> xmmA = load(vec_a);
            uint32<4> xmmB = load(vec_b);
            uint32<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes8:
            uint32<8> xmmA = load(vec_a);
            uint32<8> xmmB = load(vec_b);
            uint32<8> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    case LaneWidth::Bytes8:
        uint64_t *vec_a = reinterpret_cast<uint64_t*>(m_SP);
        uint64_t *vec_b = reinterpret_cast<uint64_t*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            uint64<2> xmmA = load(vec_a);
            uint64<2> xmmB = load(vec_b);
            uint64<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            uint64<4> xmmA = load(vec_a);
            uint64<4> xmmB = load(vec_b);
            uint64<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    break;
    case OpType::Floating:
    switch(simdByte.getLaneWidth()){
    case LaneWidth::Bytes4:
        float *vec_a = reinterpret_cast<float*>(m_SP);
        float *vec_b = reinterpret_cast<float*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            float32<2> xmmA = load(vec_a);
            float32<2> xmmB = load(vec_b);
            float32<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<float*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            float32<4> xmmA = load(vec_a);
            float32<4> xmmB = load(vec_b);
            float32<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<float*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes8:
            float32<8> xmmA = load(vec_a);
            float32<8> xmmB = load(vec_b);
            float32<8> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<float*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    case LaneWidth::Bytes8:
        double *vec_a = reinterpret_cast<double*>(m_SP);
        double *vec_b = reinterpret_cast<double*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2:
            float64<2> xmmA = load(vec_a);
            float64<2> xmmB = load(vec_b);
            float64<2> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<double*>(m_SPP), xmmC);
            break;
        case LaneCount::Lanes4:
            float64<4> xmmA = load(vec_a);
            float64<4> xmmB = load(vec_b);
            float64<4> xmmC = add(xmmA, xmmB);
            store(reinterpret_cast<double*>(m_SPP), xmmC);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    break;
    default:
        break;
    }
}

void LegacyVM::xsub(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1:
            uint8_t *vec_a = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t *vec_b = reinterpret_cast<uint8_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint8<2> xmmA = load(vec_a);
                uint8<2> xmmB = load(vec_b);
                uint8<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint8<4> xmmA = load(vec_a);
                uint8<4> xmmB = load(vec_b);
                uint8<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint8<8> xmmA = load(vec_a);
                uint8<8> xmmB = load(vec_b);
                uint8<8> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes16:
                uint8<16> xmmA = load(vec_a);
                uint8<16> xmmB = load(vec_b);
                uint8<16> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes32:
                uint8<32> xmmA = load(vec_a);
                uint8<32> xmmB = load(vec_b);
                uint8<32> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes2:
            uint16_t *vec_a = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_b = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint16<2> xmmA = load(vec_a);
                uint16<2> xmmB = load(vec_b);
                uint16<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint16<4> xmmA = load(vec_a);
                uint16<4> xmmB = load(vec_b);
                uint16<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint16<8> xmmA = load(vec_a);
                uint16<8> xmmB = load(vec_b);
                uint16<8> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes16:
                uint16<16> xmmA = load(vec_a);
                uint16<16> xmmB = load(vec_b);
                uint16<16> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes4:
            uint32_t *vec_a = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t *vec_b = reinterpret_cast<uint32_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint32<2> xmmA = load(vec_a);
                uint32<2> xmmB = load(vec_b);
                uint32<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint32<4> xmmA = load(vec_a);
                uint32<4> xmmB = load(vec_b);
                uint32<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint32<8> xmmA = load(vec_a);
                uint32<8> xmmB = load(vec_b);
                uint32<8> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes8:
            uint64_t *vec_a = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t *vec_b = reinterpret_cast<uint64_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint64<2> xmmA = load(vec_a);
                uint64<2> xmmB = load(vec_b);
                uint64<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint64<4> xmmA = load(vec_a);
                uint64<4> xmmB = load(vec_b);
                uint64<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4:
            float *vec_a = reinterpret_cast<float*>(m_SP);
            float *vec_b = reinterpret_cast<float*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float32<2> xmmA = load(vec_a);
                float32<2> xmmB = load(vec_b);
                float32<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float32<4> xmmA = load(vec_a);
                float32<4> xmmB = load(vec_b);
                float32<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                float32<8> xmmA = load(vec_a);
                float32<8> xmmB = load(vec_b);
                float32<8> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes8:
            double *vec_a = reinterpret_cast<double*>(m_SP);
            double *vec_b = reinterpret_cast<double*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float64<2> xmmA = load(vec_a);
                float64<2> xmmB = load(vec_b);
                float64<2> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float64<4> xmmA = load(vec_a);
                float64<4> xmmB = load(vec_b);
                float64<4> xmmC = sub(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xmul(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1:
            uint8_t *vec_a = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t *vec_b = reinterpret_cast<uint8_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint8<2> xmmA = load(vec_a);
                uint8<2> xmmB = load(vec_b);
                uint8<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint8<4> xmmA = load(vec_a);
                uint8<4> xmmB = load(vec_b);
                uint8<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint8<8> xmmA = load(vec_a);
                uint8<8> xmmB = load(vec_b);
                uint8<8> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes16:
                uint8<16> xmmA = load(vec_a);
                uint8<16> xmmB = load(vec_b);
                uint8<16> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes32:
                uint8<32> xmmA = load(vec_a);
                uint8<32> xmmB = load(vec_b);
                uint8<32> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint8_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes2:
            uint16_t *vec_a = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_b = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint16<2> xmmA = load(vec_a);
                uint16<2> xmmB = load(vec_b);
                uint16<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint16<4> xmmA = load(vec_a);
                uint16<4> xmmB = load(vec_b);
                uint16<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint16<8> xmmA = load(vec_a);
                uint16<8> xmmB = load(vec_b);
                uint16<8> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes16:
                uint16<16> xmmA = load(vec_a);
                uint16<16> xmmB = load(vec_b);
                uint16<16> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint16_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes4:
            uint32_t *vec_a = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t *vec_b = reinterpret_cast<uint32_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint32<2> xmmA = load(vec_a);
                uint32<2> xmmB = load(vec_b);
                uint32<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint32<4> xmmA = load(vec_a);
                uint32<4> xmmB = load(vec_b);
                uint32<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                uint32<8> xmmA = load(vec_a);
                uint32<8> xmmB = load(vec_b);
                uint32<8> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint32_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes8:
            uint64_t *vec_a = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t *vec_b = reinterpret_cast<uint64_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                uint64<2> xmmA = load(vec_a);
                uint64<2> xmmB = load(vec_b);
                uint64<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                uint64<4> xmmA = load(vec_a);
                uint64<4> xmmB = load(vec_b);
                uint64<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<uint64_t*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4:
            float *vec_a = reinterpret_cast<float*>(m_SP);
            float *vec_b = reinterpret_cast<float*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float32<2> xmmA = load(vec_a);
                float32<2> xmmB = load(vec_b);
                float32<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float32<4> xmmA = load(vec_a);
                float32<4> xmmB = load(vec_b);
                float32<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                float32<8> xmmA = load(vec_a);
                float32<8> xmmB = load(vec_b);
                float32<8> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes8:
            double *vec_a = reinterpret_cast<double*>(m_SP);
            double *vec_b = reinterpret_cast<double*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float64<2> xmmA = load(vec_a);
                float64<2> xmmB = load(vec_b);
                float64<2> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float64<4> xmmA = load(vec_a);
                float64<4> xmmB = load(vec_b);
                float64<4> xmmC = mul(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xdiv(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        // todo
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4:
            float *vec_a = reinterpret_cast<float*>(m_SP);
            float *vec_b = reinterpret_cast<float*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float32<2> xmmA = load(vec_a);
                float32<2> xmmB = load(vec_b);
                float32<2> xmmC = div(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float32<4> xmmA = load(vec_a);
                float32<4> xmmB = load(vec_b);
                float32<4> xmmC = div(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes8:
                float32<8> xmmA = load(vec_a);
                float32<8> xmmB = load(vec_b);
                float32<8> xmmC = div(xmmA, xmmB);
                store(reinterpret_cast<float*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        case LaneWidth::Bytes8:
            double *vec_a = reinterpret_cast<double*>(m_SP);
            double *vec_b = reinterpret_cast<double*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2:
                float64<2> xmmA = load(vec_a);
                float64<2> xmmB = load(vec_b);
                float64<2> xmmC = div(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            case LaneCount::Lanes4:
                float64<4> xmmA = load(vec_a);
                float64<4> xmmB = load(vec_b);
                float64<4> xmmC = div(xmmA, xmmB);
                store(reinterpret_cast<double*>(m_SPP), xmmC);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

#endif
