cmake_minimum_required(VERSION 3.1)

project(FlowAnalysis C)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(CMAKE_EXECUTABLE_SUFFIX ".axf")

include(arm-gcc-toolchain.cmake)
set(CPU_FLAGS -mthumb -mcpu=cortex-m0)
set(COMPILER_FLAGS -Os -flto)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND SOURCE_LIST 
        arrayOutOfBounds.c
        bufferOverflow.c
        dbutil.c
        divisionByZero.c
        fileLeaks.c memoryLeaks.c
        nullPointerDeref.c
        nullPointerDerefBenchmark.c
        sql.c
        sqlInjection.c
        unreachableCode.c
        useBeforeInit.c
        sensor.c
)

add_compile_options(${CPU_FLAGS} ${COMPILER_FLAGS})
add_executable(FlowAnalysis ${SOURCE_LIST})

# C++testプロジェクト作成
#include (/opt/app/parasoft/cpptest/10.5/integration/cmake/cmake/cpptest.cmake)
#cpptest_add_executable(
#abc
#[CPPTEST_PROJECT_NAME abc]
#[CPPTEST_PROJECT_LOC ../../workspace]
#SOURCES ${SOURCE_LIST}
#)
