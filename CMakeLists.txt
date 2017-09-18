cmake_minimum_required(VERSION 2.8)
project(mhook)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_definitions(-DUNICODE -D_UNICODE -DWIN32_LEAN_AND_MEAN)

file(GLOB DisasmCxx disasm-lib/*.cpp disasm-lib/*.c)
file(GLOB DisasmH disasm-lib/*.h)
set(DisasmSrc ${DisasmCxx} ${DisasmH})

file(GLOB MhookCxx mhook-lib/*.cpp mhook-lib/*.c)
file(GLOB MhookH mhook-lib/*.h)
set(MhookSrc ${MhookCxx} ${MhookH})

source_group("Source Files\\disasm-lib" FILES ${DisasmCxx})
source_group("Header Files\\disasm-lib" FILES ${DisasmH})

add_library(mhook STATIC ${DisasmSrc} ${MhookSrc})

option(BUILD_MHOOK_TEST "Building test exe for mhook" ON)

if(BUILD_MHOOK_TEST)

add_executable( MhookTest mhook-test.cpp )

target_link_libraries ( MhookTest mhook )

add_dependencies( MhookTest mhook )

endif(BUILD_MHOOK_TEST)