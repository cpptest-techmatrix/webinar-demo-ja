# CMakeのバージョンを設定
cmake_minimum_required(VERSION 3.1)


# プロジェクト名と使用する言語を設定
project(FlowAnalysis C)
set(CMAKE_C_FLAGS "-O2 -Wall")
set(CMAKE_C_FLAGS_ARM "-Os -flto -ffunction-sections -fdata-sections --specs=rdimon.specs -Wl,--gc-sections -Wl,-Map=FlowAnalysis.map")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(FlowAnalysis.axf arrayOutOfBounds.c bufferOverflow.c dbutil.c divisionByZero.c fileLeaks.c memoryLeaks.c nullPointerDeref.c nullPointerDerefBenchmark.c sql.c sqlInjection.c unreachableCode.c useBeforeInit.c)


