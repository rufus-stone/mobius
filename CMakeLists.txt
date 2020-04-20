cmake_minimum_required(VERSION 3.0.0)
project(mobius VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)

add_executable(mobius main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_compile_features(mobius PUBLIC cxx_std_17)