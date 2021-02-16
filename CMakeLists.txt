cmake_minimum_required(VERSION 3.15)
project(OS_PROJ VERSION 1.0
                  DESCRIPTION "OS project 1"
                  LANGUAGES CXX) # change these to C instead of CXX
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -flto -fuse-linker-plugin -march=native")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLANG_TIDY_CXX -checks=-*,
    bugprone-*,
    cert-*,
    clang-analyzer-*,
    concurrency-*,
    cppcoreguidelines-*,
    hicpp-*,
    llvm-*,
    misc-*,
    modernize-*,
    mpi-*,
    openmp-*,
    performance-*,
    portability-*,
    readability-*,
)
set(CLANG_TIDY_SUPPRESS_CXX
    misc-*,
)

add_executable(osshell
                ./main.cpp
       helpers.h
        )

add_executable(tests
        ./tests.cpp
        ./helpers.h
)

add_executable(snippet_runner
        ./snippet.cpp
)

