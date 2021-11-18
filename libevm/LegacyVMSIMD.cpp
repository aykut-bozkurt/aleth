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
    explicit SIMDByte(uint8_t simdByte) : simdByte(simdByte){}

    OpType getOpType() const { // 0, 1
        return static_cast<OpType>(simdByte & 0b00000001u);
    }
    LaneWidth getLaneWidth() const { // 0, 4, 8, 12
        return static_cast<LaneWidth>((simdByte & 0b00001100u) >> 2u);
    }
    LaneCount getLaneCount() const { // 0, 32, 64, 96, 128
        return static_cast<LaneCount>((simdByte & 0b11100000u) >> 5u);
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
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAdd<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdAdd<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdAdd<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAdd<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdAdd<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAdd<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<uint64<4>, uint64_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAdd<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAdd<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAdd<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xsub(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSub<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSub<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdSub<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSub<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSub<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSub<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<uint64<4>, uint64_t>();
                break;
            }
            default: {
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSub<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSub<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSub<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xmul(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            // todo
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMul<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMul<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMul<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdMul<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMul<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMul<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMul<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            // todo
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMulF<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMulF<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMulF<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMulF<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMulF<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xdiv(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        // TODO
        break;
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdDiv<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdDiv<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdDiv<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdDiv<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdDiv<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xsdiv(uint8_t)
{
    // todo
}

void LegacyVM::xmod(uint8_t)
{
    //todo
}

void LegacyVM::xsmod(uint8_t)
{
    // todo
}

void LegacyVM::xlt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<uint8<2>, mask_int8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<uint8<4>, mask_int8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdLT<uint8<8>, mask_int8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdLT<uint8<16>, mask_int8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdLT<uint8<32>, mask_int8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<uint16<2>, mask_int16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<uint16<4>, mask_int16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdLT<uint16<8>, mask_int16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdLT<uint16<16>, mask_int16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<uint32<2>, mask_int32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<uint32<4>, mask_int32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdLT<uint32<8>, mask_int32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<uint64<2>, mask_int64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<uint64<4>, mask_int64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<float32<2>, mask_float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<float32<4>, mask_float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdLT<float32<8>, mask_float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdLT<float64<2>, mask_float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdLT<float64<4>, mask_float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xslt(uint8_t)
{
    // todo
}

void LegacyVM::xgt(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<uint8<2>, mask_int8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<uint8<4>, mask_int8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdGT<uint8<8>, mask_int8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdGT<uint8<16>, mask_int8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdGT<uint8<32>, mask_int8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<uint16<2>, mask_int16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<uint16<4>, mask_int16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdGT<uint16<8>, mask_int16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdGT<uint16<16>, mask_int16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<uint32<2>, mask_int32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<uint32<4>, mask_int32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdGT<uint32<8>, mask_int32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<uint64<2>, mask_int64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<uint64<4>, mask_int64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<float32<2>, mask_float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<float32<4>, mask_float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdGT<float32<8>, mask_float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdGT<float64<2>, mask_float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdGT<float64<4>, mask_float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
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
}

void LegacyVM::xsgt(uint8_t)
{
    // todo
}

void LegacyVM::xeq(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<uint8<2>, mask_int8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<uint8<4>, mask_int8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdEQ<uint8<8>, mask_int8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdEQ<uint8<16>, mask_int8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdEQ<uint8<32>, mask_int8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<uint16<2>, mask_int16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<uint16<4>, mask_int16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdEQ<uint16<8>, mask_int16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdEQ<uint16<16>, mask_int16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<uint32<2>, mask_int32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<uint32<4>, mask_int32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdEQ<uint32<8>, mask_int32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<uint64<2>, mask_int64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<uint64<4>, mask_int64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<float32<2>, mask_float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<float32<4>, mask_float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdEQ<float32<8>, mask_float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdEQ<float64<2>, mask_float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdEQ<float64<4>, mask_float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
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
}

void LegacyVM::xzero(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<uint8<2>, mask_int8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<uint8<4>, mask_int8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdIsZero<uint8<8>, mask_int8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdIsZero<uint8<16>, mask_int8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdIsZero<uint8<32>, mask_int8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<uint16<2>, mask_int16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<uint16<4>, mask_int16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdIsZero<uint16<8>, mask_int16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdIsZero<uint16<16>, mask_int16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<uint32<2>, mask_int32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<uint32<4>, mask_int32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdIsZero<uint32<8>, mask_int32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<uint64<2>, mask_int64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<uint64<4>, mask_int64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<float32<2>, mask_float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<float32<4>, mask_float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdIsZero<float32<8>, mask_float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdIsZero<float64<2>, mask_float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdIsZero<float64<4>, mask_float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xand(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAnd<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdAnd<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdAnd<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAnd<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdAnd<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAnd<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdAnd<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdAnd<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdAnd<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xoor(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int:
    {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdOr<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdOr<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdOr<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdOr<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdOr<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdOr<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating:
    {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdOr<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdOr<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdOr<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
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
}

void LegacyVM::xxor(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdXor<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdXor<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdXor<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdXor<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdXor<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdXor<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdXor<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdXor<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdXor<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default:{
        break;
    }
    }
}

void LegacyVM::xnot(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdNot<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdNot<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdNot<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdNot<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdNot<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdNot<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdNot<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<uint32<2>, uint32_t>();
                break;

            }
            case LaneCount::Lanes4: {
                simdNot<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdNot<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdNot<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdNot<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdNot<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdNot<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdNot<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default: {
        break;
    }
    }
}

void LegacyVM::xshl(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHL<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHL<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHL<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSHL<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdSHL<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHL<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHL<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHL<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSHL<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHL<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHL<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHL<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            // not supported
            break;
        }
        default:
            break;
        }
        break;
    }
    case OpType::Floating: {
        // not supported
        break;
    }
    default:{
        break;
    }
    }
}

void LegacyVM::xshr(uint8_t simd)
{
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHR<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHR<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHR<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSHR<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdSHR<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHR<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHR<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHR<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdSHR<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdSHR<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdSHR<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdSHR<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            // not supported
            break;
        }
        default:
            break;
        }
        break;
    }
    case OpType::Floating: {
        // not supported
        break;
    }
    default: {
        break;
    }
    }
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

void LegacyVM::xpush (uint8_t simd){
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdPush<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdPush<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdPush<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdPush<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdPush<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdPush<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdPush<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdPush<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdPush<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default:{
        break;
    }
    }
}

void LegacyVM::xmload  (uint8_t simd){
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMLoad<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdMLoad<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdMLoad<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMLoad<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdMLoad<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMLoad<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMLoad<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMLoad<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMLoad<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default:{
        break;
    }
    }
}

void LegacyVM::xmstore (uint8_t simd){
    auto simdByte = SIMDByte{simd};

    switch(simdByte.getOpType()){
    case OpType::Int: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes1: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<uint8<2>, uint8_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<uint8<4>, uint8_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMStore<uint8<8>, uint8_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdMStore<uint8<16>, uint8_t>();
                break;
            }
            case LaneCount::Lanes32: {
                simdMStore<uint8<32>, uint8_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes2: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<uint16<2>, uint16_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<uint16<4>, uint16_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMStore<uint16<8>, uint16_t>();
                break;
            }
            case LaneCount::Lanes16: {
                simdMStore<uint16<16>, uint16_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<uint32<2>, uint32_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<uint32<4>, uint32_t>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMStore<uint32<8>, uint32_t>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<uint64<2>, uint64_t>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<uint64<4>, uint64_t>();
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
    }
    case OpType::Floating: {
        switch (simdByte.getLaneWidth())
        {
        case LaneWidth::Bytes4: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<float32<2>, float>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<float32<4>, float>();
                break;
            }
            case LaneCount::Lanes8: {
                simdMStore<float32<8>, float>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        case LaneWidth::Bytes8: {
            switch (simdByte.getLaneCount())
            {
            case LaneCount::Lanes2: {
                simdMStore<float64<2>, double>();
                break;
            }
            case LaneCount::Lanes4: {
                simdMStore<float64<4>, double>();
                break;
            }
            default: {
                break;
            }
            }
            break;
        }
        default: {
            break;
        }
        }
        break;
    }
    default:{
        break;
    }
    }
}

void LegacyVM::xsload  (uint8_t){
    //todo
    //m_SPP[0] = m_ext->store(m_SP[0]);
}

void LegacyVM::xsstore (uint8_t){
    //todo
    //m_ext->setStore(m_SP[0], m_SP[1]);
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

void LegacyVM::xwidetov(uint8_t)
{
    // todo
}

void LegacyVM::xvtowide(uint8_t)
{
    // todo
}

#endif
