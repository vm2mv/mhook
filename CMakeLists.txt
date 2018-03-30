cmake_minimum_required(VERSION 2.8)
project(mhook)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib" CACHE PATH "Installation directory for libraries")
set(INSTALL_INC_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "Installation directory for headers")

add_definitions(-DNO_SANITY_CHECKS -DUNICODE -D_UNICODE -DWIN32_LEAN_AND_MEAN)

file(GLOB DisasmSrc disasm-lib/*.c disasm-lib/*.h)
file(GLOB MhookSrc mhook-lib/*.cpp mhook-lib/*.h)
SET(MHOOK_PUBLIC_HDRS mhook-lib/mhook.h)

source_group("disasm-lib" FILES ${DisasmSrc})
source_group("mhook-lib" FILES ${MhookSrc})

add_library(mhook STATIC ${DisasmSrc} ${MhookSrc})
target_include_directories(mhook INTERFACE .)

option(BUILD_MHOOK_TEST "Building test exe for mhook" OFF)

if(BUILD_MHOOK_TEST)
    add_executable(mhook-test 
        mhook-test/mhook-test.cpp
        mhook-test/stdafx.cpp
        mhook-test/stdafx.h
        )
    set_target_properties(mhook-test PROPERTIES COMPILE_FLAGS "/Yustdafx.h")
    set_source_files_properties(mhook-test/stdafx.cpp PROPERTIES COMPILE_FLAGS "/Ycstdafx.h")
    target_link_libraries(mhook-test mhook)
endif(BUILD_MHOOK_TEST)

install(TARGETS mhook
    ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
    LIBRARY DESTINATION "${INSTALL_LIB_DIR}" )
install(FILES ${MHOOK_PUBLIC_HDRS} DESTINATION "${INSTALL_INC_DIR}/mhook-lib")