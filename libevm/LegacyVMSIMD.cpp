#include "LegacyVM.h"
#include <simdpp/simd.h>

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
    case LaneWidth::Bytes1: {
        uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
        uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

        switch (simdByte.getLaneCount())
        {
        case LaneCount::Lanes2: {
            uint8<2> lane2WIdth1A = load(vec_1bytesA);
            uint8<2> lane2WIdth1B = load(vec_1bytesB);
            uint8<2> lane2WIdth1C = add(lane2WIdth1A, lane2WIdth1B);
            store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
            break;
        }
        case LaneCount::Lanes4: {
            uint8<4> lane4WIdth1A = load(vec_1bytesA);
            uint8<4> lane4WIdth1B = load(vec_1bytesB);
            uint8<4> lane4WIdth1C = add(lane4WIdth1A, lane4WIdth1B);
            store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
            break;
        }
        case LaneCount::Lanes8: {
            uint8<8> lane8WIdth1A = load(vec_1bytesA);
            uint8<8> lane8WIdth1B = load(vec_1bytesB);
            uint8<8> lane8WIdth1C = add(lane8WIdth1A, lane8WIdth1B);
            store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
            break;
        }
        case LaneCount::Lanes16: {
            uint8<16> lane16WIdth1A = load(vec_1bytesA);
            uint8<16> lane16WIdth1B = load(vec_1bytesB);
            uint8<16> lane16WIdth1C = add(lane16WIdth1A, lane16WIdth1B);
            store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
            break;
        }
        case LaneCount::Lanes32: {
            uint8<32> lane32WIdth1A = load(vec_1bytesA);
            uint8<32> lane32WIdth1B = load(vec_1bytesB);
            uint8<32> lane32WIdth1C = add(lane32WIdth1A, lane32WIdth1B);
            store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C);
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    case LaneWidth::Bytes2:
    {
        uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
        uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

        switch(simdByte.getLaneCount()){
        case LaneCount::Lanes2: {
            uint16<2> lane2WIdth2A = load(vec_2bytesA);
            uint16<2> lane2WIdth2B = load(vec_2bytesB);
            uint16<2> lane2WIdth2C = add(lane2WIdth2A, lane2WIdth2B);
            store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
            break;
        }
        case LaneCount::Lanes4: {
            uint16<4> lane4WIdth2A = load(vec_2bytesA);
            uint16<4> lane4WIdth2B = load(vec_2bytesB);
            uint16<4> lane4WIdth2C = add(lane4WIdth2A, lane4WIdth2B);
            store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
            break;
        }
        case LaneCount::Lanes8: {
            uint16<8> lane8WIdth2A = load(vec_2bytesA);
            uint16<8> lane8WIdth2B = load(vec_2bytesB);
            uint16<8> lane8WIdth2C = add(lane8WIdth2A, lane8WIdth2B);
            store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
            break;
        }
        case LaneCount::Lanes16: {
            uint16<16> lane16WIdth2A = load(vec_2bytesA);
            uint16<16> lane16WIdth2B = load(vec_2bytesB);
            uint16<16> lane16WIdth2C = add(lane16WIdth2A, lane16WIdth2B);
            store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case LaneWidth::Bytes4: {
        uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
        uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

        switch (simdByte.getLaneCount())
        {
        case LaneCount::Lanes2:
        {
            uint32<2> lane2WIdth4A = load(vec_4bytesA);
            uint32<2> lane2WIdth4B = load(vec_4bytesB);
            uint32<2> lane2WIdth4C = add(lane2WIdth4A, lane2WIdth4B);
            store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
            break;
        }
        case LaneCount::Lanes4: {
            uint32<4> lane4WIdth4A = load(vec_4bytesA);
            uint32<4> lane4WIdth4B = load(vec_4bytesB);
            uint32<4> lane4WIdth4C = add(lane4WIdth4A, lane4WIdth4B);
            store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
            break;
        }
        case LaneCount::Lanes8: {
            uint32<8> lane8WIdth4A = load(vec_4bytesA);
            uint32<8> lane8WIdth4B = load(vec_4bytesB);
            uint32<8> lane8WIdth4C = add(lane8WIdth4A, lane8WIdth4B);
            store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case LaneWidth::Bytes8: {
        uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
        uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

        switch (simdByte.getLaneCount())
        {
        case LaneCount::Lanes2: {
            uint64<2> lane2WIdth8A = load(vec_8bytesA);
            uint64<2> lane2WIdth8B = load(vec_8bytesB);
            uint64<2> lane2WIdth8C = add(lane2WIdth8A, lane2WIdth8B);
            store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
            break;
        }
        case LaneCount::Lanes4: {
            uint64<4> lane4WIdth8A = load(vec_8bytesA);
            uint64<4> lane4WIdth8B = load(vec_8bytesB);
            uint64<4> lane4WIdth8C = add(lane4WIdth8A, lane4WIdth8B);
            store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default:
        break;
    }
    break;
    case OpType::Floating:
    switch(simdByte.getLaneWidth()){
    case LaneWidth::Bytes4: {
        float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
        float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

        switch (simdByte.getLaneCount())
        {
        case LaneCount::Lanes2: {
            float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
            float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
            float32<2> lane2WIdth4FloatC = add(lane2WIdth4FloatA, lane2WIdth4FloatB);
            store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
            break;
        }
        case LaneCount::Lanes4: {
            float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
            float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
            float32<4> lane4WIdth4FloatC = add(lane4WIdth4FloatA, lane4WIdth4FloatB);
            store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
            break;
        }
        case LaneCount::Lanes8: {
            float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
            float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
            float32<8> lane8WIdth4FloatC = add(lane8WIdth4FloatA, lane8WIdth4FloatB);
            store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    case LaneWidth::Bytes8: {
        double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
        double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

        switch (simdByte.getLaneCount())
        {
        case LaneCount::Lanes2: {
            float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
            float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
            float64<2> lane2WIdth8FloatC = add(lane2WIdth8FloatA, lane2WIdth8FloatB);
            store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
            break;
        }
        case LaneCount::Lanes4: {
            float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
            float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
            float64<4> lane4WIdth8FloatC = add(lane4WIdth8FloatA, lane4WIdth8FloatB);
            store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    default:
    {
        break;
    }
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
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                uint8<2> lane2WIdth1C = sub(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                uint8<4> lane4WIdth1C = sub(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                uint8<8> lane8WIdth1C = sub(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                uint8<16> lane16WIdth1C = sub(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                uint8<32> lane32WIdth1C = sub(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                uint16<2> lane2WIdth2C = sub(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                uint16<4> lane4WIdth2C = sub(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                uint16<8> lane8WIdth2C = sub(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                uint16<16> lane16WIdth2C = sub(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                uint32<2> lane2WIdth4C = sub(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                uint32<4> lane4WIdth4C = sub(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                uint32<8> lane8WIdth4C = sub(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                uint64<2> lane2WIdth8C = sub(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                uint64<4> lane4WIdth8C = sub(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = sub(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = sub(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = sub(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = sub(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = sub(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
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
        case LaneWidth::Bytes1: {
            // todo
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                uint16<2> lane2WIdth2C = mul_lo(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                uint16<4> lane4WIdth2C = mul_lo(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                uint16<8> lane8WIdth2C = mul_lo(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                uint16<16> lane16WIdth2C = mul_lo(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                uint32<2> lane2WIdth4C = mul_lo(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                uint32<4> lane4WIdth4C = mul_lo(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                uint32<8> lane8WIdth4C = mul_lo(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            // todo
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = mul(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = mul(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = mul(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = mul(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = mul(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
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
        // TODO
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = div(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = div(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = div(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = div(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = div(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xsdiv(uint8_t simd)
{
    xdiv(simd);
}

void LegacyVM::xmod(uint8_t)
{
    //todo
}

void LegacyVM::xsmod(uint8_t simd)
{
    xmod(simd);
}

void LegacyVM::xlt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_lt(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_lt(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_lt(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_lt(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_lt(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_lt(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_lt(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_lt(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_lt(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_lt(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_lt(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_lt(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_lt(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_lt(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<2> lane2WIdth4FloatC = cmp_lt(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<4> lane4WIdth4FloatC = cmp_lt(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<8> lane8WIdth4FloatC = cmp_lt(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<2> lane2WIdth8FloatC = cmp_lt(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<4> lane4WIdth8FloatC = cmp_lt(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xslt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            int8_t* vec_1bytesA = reinterpret_cast<int8_t*>(m_SP);
            int8_t* vec_1bytesB = reinterpret_cast<int8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                int8<2> lane2WIdth1A = load(vec_1bytesA);
                int8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_lt(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int8<4> lane4WIdth1A = load(vec_1bytesA);
                int8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_lt(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int8<8> lane8WIdth1A = load(vec_1bytesA);
                int8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_lt(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                int8<16> lane16WIdth1A = load(vec_1bytesA);
                int8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_lt(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                int8<32> lane32WIdth1A = load(vec_1bytesA);
                int8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_lt(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            int16_t *vec_2bytesA = reinterpret_cast<int16_t*>(m_SP);
            int16_t *vec_2bytesB = reinterpret_cast<int16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                int16<2> lane2WIdth2A = load(vec_2bytesA);
                int16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_lt(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int16<4> lane4WIdth2A = load(vec_2bytesA);
                int16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_lt(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int16<8> lane8WIdth2A = load(vec_2bytesA);
                int16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_lt(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                int16<16> lane16WIdth2A = load(vec_2bytesA);
                int16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_lt(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            int32_t* vec_4bytesA = reinterpret_cast<int32_t*>(m_SP);
            int32_t* vec_4bytesB = reinterpret_cast<int32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                int32<2> lane2WIdth4A = load(vec_4bytesA);
                int32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_lt(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int32<4> lane4WIdth4A = load(vec_4bytesA);
                int32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_lt(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int32<8> lane8WIdth4A = load(vec_4bytesA);
                int32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_lt(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            int64_t* vec_8bytesA = reinterpret_cast<int64_t*>(m_SP);
            int64_t* vec_8bytesB = reinterpret_cast<int64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                int64<2> lane2WIdth8A = load(vec_8bytesA);
                int64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_lt(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<int64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int64<4> lane4WIdth8A = load(vec_8bytesA);
                int64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_lt(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<int64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        xlt(simd);
        break;
    default:
        break;
    }
}

void LegacyVM::xgt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_gt(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_gt(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_gt(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_gt(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_gt(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_gt(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_gt(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_gt(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_gt(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_gt(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_gt(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_gt(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_gt(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_gt(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<2> lane2WIdth4FloatC = cmp_gt(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<4> lane4WIdth4FloatC = cmp_gt(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<8> lane8WIdth4FloatC = cmp_gt(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<2> lane2WIdth8FloatC = cmp_gt(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<4> lane4WIdth8FloatC = cmp_gt(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xsgt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            int8_t* vec_1bytesA = reinterpret_cast<int8_t*>(m_SP);
            int8_t* vec_1bytesB = reinterpret_cast<int8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                int8<2> lane2WIdth1A = load(vec_1bytesA);
                int8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_gt(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int8<4> lane4WIdth1A = load(vec_1bytesA);
                int8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_gt(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int8<8> lane8WIdth1A = load(vec_1bytesA);
                int8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_gt(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                int8<16> lane16WIdth1A = load(vec_1bytesA);
                int8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_gt(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                int8<32> lane32WIdth1A = load(vec_1bytesA);
                int8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_gt(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<int8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            int16_t *vec_2bytesA = reinterpret_cast<int16_t*>(m_SP);
            int16_t *vec_2bytesB = reinterpret_cast<int16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                int16<2> lane2WIdth2A = load(vec_2bytesA);
                int16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_gt(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int16<4> lane4WIdth2A = load(vec_2bytesA);
                int16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_gt(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int16<8> lane8WIdth2A = load(vec_2bytesA);
                int16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_gt(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                int16<16> lane16WIdth2A = load(vec_2bytesA);
                int16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_gt(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<int16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            int32_t* vec_4bytesA = reinterpret_cast<int32_t*>(m_SP);
            int32_t* vec_4bytesB = reinterpret_cast<int32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                int32<2> lane2WIdth4A = load(vec_4bytesA);
                int32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_gt(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int32<4> lane4WIdth4A = load(vec_4bytesA);
                int32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_gt(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                int32<8> lane8WIdth4A = load(vec_4bytesA);
                int32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_gt(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<int32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            int64_t* vec_8bytesA = reinterpret_cast<int64_t*>(m_SP);
            int64_t* vec_8bytesB = reinterpret_cast<int64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                int64<2> lane2WIdth8A = load(vec_8bytesA);
                int64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_gt(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<int64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                int64<4> lane4WIdth8A = load(vec_8bytesA);
                int64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_gt(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<int64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        xgt(simd);
        break;
    default:
        break;
    }
}

void LegacyVM::xeq(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_eq(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_eq(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_eq(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_eq(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_eq(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_eq(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_eq(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_eq(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_eq(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_eq(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_eq(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_eq(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_eq(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_eq(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<2> lane2WIdth4FloatC = cmp_eq(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<4> lane4WIdth4FloatC = cmp_eq(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<8> lane8WIdth4FloatC = cmp_eq(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<2> lane2WIdth8FloatC = cmp_eq(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<4> lane4WIdth8FloatC = cmp_eq(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xzero(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t vec_1bytesB[32] = {0};

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                mask_int8<2> lane2WIdth1C = cmp_eq(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                mask_int8<4> lane4WIdth1C = cmp_eq(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                mask_int8<8> lane8WIdth1C = cmp_eq(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                mask_int8<16> lane16WIdth1C = cmp_eq(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C.unmask());
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                mask_int8<32> lane32WIdth1C = cmp_eq(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t vec_2bytesB[16] = {0};

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                mask_int16<2> lane2WIdth2C = cmp_eq(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                mask_int16<4> lane4WIdth2C = cmp_eq(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                mask_int16<8> lane8WIdth2C = cmp_eq(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C.unmask());
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                mask_int16<16> lane16WIdth2C = cmp_eq(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t vec_4bytesB[8] = {0};

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                mask_int32<2> lane2WIdth4C = cmp_eq(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                mask_int32<4> lane4WIdth4C = cmp_eq(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                mask_int32<8> lane8WIdth4C = cmp_eq(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t vec_8bytesB[4] = {0};

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                mask_int64<2> lane2WIdth8C = cmp_eq(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                mask_int64<4> lane4WIdth8C = cmp_eq(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float vec_4bytesFloatB[8] = {0};

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<2> lane2WIdth4FloatC = cmp_eq(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<4> lane4WIdth4FloatC = cmp_eq(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC.unmask());
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                mask_float32<8> lane8WIdth4FloatC = cmp_eq(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC.unmask());
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double vec_8bytesFloatB[4] = {0};

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<2> lane2WIdth8FloatC = cmp_eq(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC.unmask());
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                mask_float64<4> lane4WIdth8FloatC = cmp_eq(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC.unmask());
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xand(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                uint8<2> lane2WIdth1C = simdpp::bit_and(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                uint8<4> lane4WIdth1C = simdpp::bit_and(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                uint8<8> lane8WIdth1C = simdpp::bit_and(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                uint8<16> lane16WIdth1C = simdpp::bit_and(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                uint8<32> lane32WIdth1C = simdpp::bit_and(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                uint16<2> lane2WIdth2C = simdpp::bit_and(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                uint16<4> lane4WIdth2C = simdpp::bit_and(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                uint16<8> lane8WIdth2C = simdpp::bit_and(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                uint16<16> lane16WIdth2C = simdpp::bit_and(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                uint32<2> lane2WIdth4C = simdpp::bit_and(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                uint32<4> lane4WIdth4C = simdpp::bit_and(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                uint32<8> lane8WIdth4C = simdpp::bit_and(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                uint64<2> lane2WIdth8C = simdpp::bit_and(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                uint64<4> lane4WIdth8C = simdpp::bit_and(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = simdpp::bit_and(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = simdpp::bit_and(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = simdpp::bit_and(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = simdpp::bit_and(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = simdpp::bit_and(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xoor(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                uint8<2> lane2WIdth1C = simdpp::bit_or(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                uint8<4> lane4WIdth1C = simdpp::bit_or(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                uint8<8> lane8WIdth1C = simdpp::bit_or(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                uint8<16> lane16WIdth1C = simdpp::bit_or(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                uint8<32> lane32WIdth1C = simdpp::bit_or(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                uint16<2> lane2WIdth2C = simdpp::bit_or(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                uint16<4> lane4WIdth2C = simdpp::bit_or(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                uint16<8> lane8WIdth2C = simdpp::bit_or(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                uint16<16> lane16WIdth2C = simdpp::bit_or(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                uint32<2> lane2WIdth4C = simdpp::bit_or(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                uint32<4> lane4WIdth4C = simdpp::bit_or(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                uint32<8> lane8WIdth4C = simdpp::bit_or(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                uint64<2> lane2WIdth8C = simdpp::bit_or(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                uint64<4> lane4WIdth8C = simdpp::bit_or(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = simdpp::bit_or(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = simdpp::bit_or(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = simdpp::bit_or(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = simdpp::bit_or(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = simdpp::bit_or(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xxor(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);
            uint8_t* vec_1bytesB = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1B = load(vec_1bytesB);
                uint8<2> lane2WIdth1C = simdpp::bit_xor(lane2WIdth1A, lane2WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1B = load(vec_1bytesB);
                uint8<4> lane4WIdth1C = simdpp::bit_xor(lane4WIdth1A, lane4WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1B = load(vec_1bytesB);
                uint8<8> lane8WIdth1C = simdpp::bit_xor(lane8WIdth1A, lane8WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1B = load(vec_1bytesB);
                uint8<16> lane16WIdth1C = simdpp::bit_xor(lane16WIdth1A, lane16WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                uint8<32> lane32WIdth1B = load(vec_1bytesB);
                uint8<32> lane32WIdth1C = simdpp::bit_xor(lane32WIdth1A, lane32WIdth1B);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);
            uint16_t *vec_2bytesB = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2B = load(vec_2bytesB);
                uint16<2> lane2WIdth2C = simdpp::bit_xor(lane2WIdth2A, lane2WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2B = load(vec_2bytesB);
                uint16<4> lane4WIdth2C = simdpp::bit_xor(lane4WIdth2A, lane4WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2B = load(vec_2bytesB);
                uint16<8> lane8WIdth2C = simdpp::bit_xor(lane8WIdth2A, lane8WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2B = load(vec_2bytesB);
                uint16<16> lane16WIdth2C = simdpp::bit_xor(lane16WIdth2A, lane16WIdth2B);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);
            uint32_t* vec_4bytesB = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4B = load(vec_4bytesB);
                uint32<2> lane2WIdth4C = simdpp::bit_xor(lane2WIdth4A, lane2WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4B = load(vec_4bytesB);
                uint32<4> lane4WIdth4C = simdpp::bit_xor(lane4WIdth4A, lane4WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4B = load(vec_4bytesB);
                uint32<8> lane8WIdth4C = simdpp::bit_xor(lane8WIdth4A, lane8WIdth4B);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);
            uint64_t* vec_8bytesB = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8B = load(vec_8bytesB);
                uint64<2> lane2WIdth8C = simdpp::bit_xor(lane2WIdth8A, lane2WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8B = load(vec_8bytesB);
                uint64<4> lane4WIdth8C = simdpp::bit_xor(lane4WIdth8A, lane4WIdth8B);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);
            float* vec_4bytesFloatB = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatB = load(vec_4bytesFloatB);
                float32<2> lane2WIdth4FloatC = simdpp::bit_xor(lane2WIdth4FloatA, lane2WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatB = load(vec_4bytesFloatB);
                float32<4> lane4WIdth4FloatC = simdpp::bit_xor(lane4WIdth4FloatA, lane4WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatB = load(vec_4bytesFloatB);
                float32<8> lane8WIdth4FloatC = simdpp::bit_xor(lane8WIdth4FloatA, lane8WIdth4FloatB);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);
            double* vec_8bytesFloatB = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatB = load(vec_8bytesFloatB);
                float64<2> lane2WIdth8FloatC = simdpp::bit_xor(lane2WIdth8FloatA, lane2WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatB = load(vec_8bytesFloatB);
                float64<4> lane4WIdth8FloatC = simdpp::bit_xor(lane4WIdth8FloatA, lane4WIdth8FloatB);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xnot(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes1: {
            uint8_t* vec_1bytesA = reinterpret_cast<uint8_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint8<2> lane2WIdth1A = load(vec_1bytesA);
                uint8<2> lane2WIdth1C = simdpp::bit_not(lane2WIdth1A);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane2WIdth1C);
                break;
            }
            case LaneCount::Lanes4: {
                uint8<4> lane4WIdth1A = load(vec_1bytesA);
                uint8<4> lane4WIdth1C = simdpp::bit_not(lane4WIdth1A);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane4WIdth1C);
                break;
            }
            case LaneCount::Lanes8: {
                uint8<8> lane8WIdth1A = load(vec_1bytesA);
                uint8<8> lane8WIdth1C = simdpp::bit_not(lane8WIdth1A);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane8WIdth1C);
                break;
            }
            case LaneCount::Lanes16: {
                uint8<16> lane16WIdth1A = load(vec_1bytesA);
                uint8<16> lane16WIdth1C = simdpp::bit_not(lane16WIdth1A);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane16WIdth1C);
                break;
            }
            case LaneCount::Lanes32: {
                uint8<32> lane32WIdth1A = load(vec_1bytesA);
                store(reinterpret_cast<uint8_t*>(m_SPP), lane32WIdth1A);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2:
        {
            uint16_t *vec_2bytesA = reinterpret_cast<uint16_t*>(m_SP);

            switch(simdByte.getLaneCount()){
            case LaneCount::Lanes2: {
                uint16<2> lane2WIdth2A = load(vec_2bytesA);
                uint16<2> lane2WIdth2C = simdpp::bit_not(lane2WIdth2A);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane2WIdth2C);
                break;
            }
            case LaneCount::Lanes4: {
                uint16<4> lane4WIdth2A = load(vec_2bytesA);
                uint16<4> lane4WIdth2C = simdpp::bit_not(lane4WIdth2A);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane4WIdth2C);
                break;
            }
            case LaneCount::Lanes8: {
                uint16<8> lane8WIdth2A = load(vec_2bytesA);
                uint16<8> lane8WIdth2C = simdpp::bit_not(lane8WIdth2A);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane8WIdth2C);
                break;
            }
            case LaneCount::Lanes16: {
                uint16<16> lane16WIdth2A = load(vec_2bytesA);
                uint16<16> lane16WIdth2C = simdpp::bit_not(lane16WIdth2A);
                store(reinterpret_cast<uint16_t*>(m_SPP), lane16WIdth2C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            uint32_t* vec_4bytesA = reinterpret_cast<uint32_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2:
            {
                uint32<2> lane2WIdth4A = load(vec_4bytesA);
                uint32<2> lane2WIdth4C = simdpp::bit_not(lane2WIdth4A);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane2WIdth4C);
                break;
            }
            case LaneCount::Lanes4: {
                uint32<4> lane4WIdth4A = load(vec_4bytesA);
                uint32<4> lane4WIdth4C = simdpp::bit_not(lane4WIdth4A);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane4WIdth4C);
                break;
            }
            case LaneCount::Lanes8: {
                uint32<8> lane8WIdth4A = load(vec_4bytesA);
                uint32<8> lane8WIdth4C = simdpp::bit_not(lane8WIdth4A);
                store(reinterpret_cast<uint32_t*>(m_SPP), lane8WIdth4C);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            uint64_t* vec_8bytesA = reinterpret_cast<uint64_t*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                uint64<2> lane2WIdth8A = load(vec_8bytesA);
                uint64<2> lane2WIdth8C = simdpp::bit_not(lane2WIdth8A);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane2WIdth8C);
                break;
            }
            case LaneCount::Lanes4: {
                uint64<4> lane4WIdth8A = load(vec_8bytesA);
                uint64<4> lane4WIdth8C = simdpp::bit_not(lane4WIdth8A);
                store(reinterpret_cast<uint64_t*>(m_SPP), lane4WIdth8C);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default:
            break;
        }
        break;
    case OpType::Floating:
        switch(simdByte.getLaneWidth()){
        case LaneWidth::Bytes4: {
            float* vec_4bytesFloatA = reinterpret_cast<float*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float32<2> lane2WIdth4FloatA = load(vec_4bytesFloatA);
                float32<2> lane2WIdth4FloatC = simdpp::bit_not(lane2WIdth4FloatA);
                store(reinterpret_cast<float*>(m_SPP), lane2WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float32<4> lane4WIdth4FloatA = load(vec_4bytesFloatA);
                float32<4> lane4WIdth4FloatC = simdpp::bit_not(lane4WIdth4FloatA);
                store(reinterpret_cast<float*>(m_SPP), lane4WIdth4FloatC);
                break;
            }
            case LaneCount::Lanes8: {
                float32<8> lane8WIdth4FloatA = load(vec_4bytesFloatA);
                float32<8> lane8WIdth4FloatC = simdpp::bit_not(lane8WIdth4FloatA);
                store(reinterpret_cast<float*>(m_SPP), lane8WIdth4FloatC);
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            double* vec_8bytesFloatA = reinterpret_cast<double*>(m_SP);

            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                float64<2> lane2WIdth8FloatA = load(vec_8bytesFloatA);
                float64<2> lane2WIdth8FloatC = simdpp::bit_not(lane2WIdth8FloatA);
                store(reinterpret_cast<double*>(m_SPP), lane2WIdth8FloatC);
                break;
            }
            case LaneCount::Lanes4: {
                float64<4> lane4WIdth8FloatA = load(vec_8bytesFloatA);
                float64<4> lane4WIdth8FloatC = simdpp::bit_not(lane4WIdth8FloatA);
                store(reinterpret_cast<double*>(m_SPP), lane4WIdth8FloatC);
                break;
            }
            default:
            {
                break;
            }
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    default:
        break;
    }
}

void LegacyVM::xshl(uint8_t)
{
    //todo
}

void LegacyVM::xshr(uint8_t)
{
    //todo
}

void LegacyVM::xsar(uint8_t)
{
    //todo
}

void LegacyVM::xrol(uint8_t)
{
    //todo
}

void LegacyVM::xror(uint8_t)
{
    //todo
}

void LegacyVM::xmload  (uint8_t){
    //todo
}

void LegacyVM::xmstore (uint8_t){
    //todo
}

void LegacyVM::xsload  (uint8_t){
    //todo
}

void LegacyVM::xsstore (uint8_t){
    //todo
}

void LegacyVM::xvtowide(uint8_t){
    //todo
}

void LegacyVM::xwidetov(uint8_t){
    //todo
}

void LegacyVM::xpush   (uint8_t){
    //todo
}

void LegacyVM::xput (uint8_t, uint8_t){
    //todo
}

void LegacyVM::xget (uint8_t, uint8_t){
    //todo
}

void LegacyVM::xswizzle(uint8_t){
    //todo
}

void LegacyVM::xshuffle(uint8_t){
    //todo
}

u256 LegacyVM::vtow(uint8_t, const u256&){
    //todo
    return u256{};
}

void LegacyVM::wtov(uint8_t, u256, u256&){
    //todo
}

#endif
