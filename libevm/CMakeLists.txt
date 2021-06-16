
set(sources
    EVMC.cpp EVMC.h
    ExtVMFace.cpp ExtVMFace.h
    Instruction.cpp Instruction.h
    LegacyVM.cpp LegacyVM.h
    LegacyVMSIMD.cpp
    LegacyVMConfig.h
    LegacyVMCalls.cpp
    LegacyVMOpt.cpp
    VMFace.h
    VMFactory.cpp VMFactory.h
)

add_library(evm ${sources})

target_link_libraries(
    evm
    PUBLIC ethcore devcore evmc::evmc
    PRIVATE aleth-interpreter aleth-buildinfo jsoncpp_lib_static Boost::program_options evmc::loader
)

include(../libsimdpp/cmake/SimdppMultiarch.cmake)
simdpp_get_runnable_archs(RUNNABLE_ARCHS)
message("Supported libsimdpp archs are ${RUNNABLE_ARCHS}")

include(../cmake/FastestAvailableArch.cmake)
set_fastest_available_x86archs(RUNNABLE_ARCHS)

if(EVM_OPTIMIZE)
    target_compile_definitions(evm PRIVATE EVM_OPTIMIZE)
endif()
