cmake_minimum_required(VERSION 2.8)
project(mhook)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_definitions(-DNO_SANITY_CHECKS -DUNICODE -D_UNICODE -DWIN32_LEAN_AND_MEAN)

file(GLOB DisasmSrc disasm-lib/*.c disasm-lib/*.h)
file(GLOB MhookSrc mhook-lib/*.cpp mhook-lib/*.h)

source_group("disasm-lib" FILES ${DisasmSrc})
source_group("mhook-lib" FILES ${MhookSrc})

add_library(mhook STATIC ${DisasmSrc} ${MhookSrc})

option(BUILD_MHOOK_TEST "Building test exe for mhook" OFF)

if(BUILD_MHOOK_TEST)
    add_executable(mhook-test mhook-test.cpp)
    target_link_libraries(mhook-test mhook)
endif(BUILD_MHOOK_TEST)