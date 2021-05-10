# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)

# プロジェクト名と使用する言語を設定
project(FlowAnalysis CC)

# a.outという実行ファイルをmain.cppとhello.cppから作成
add_executable(flowanalysis.out arrayOutOfBounds.c bufferOverflow.c dbutil.c divisionByZero.c fileLeaks.c memoryLeaks.c nullPointerDeref.c nullPointerDerefBenchmark.c sql.c sqlInjection.c unreachableCode.c useBeforeInit.c)
