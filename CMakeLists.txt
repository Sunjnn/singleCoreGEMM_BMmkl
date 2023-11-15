cmake_minimum_required(VERSION 3.13)

project(singleCoreGEMM_BMmkl LANGUAGES CXX)

find_package(MKL CONFIG REQUIRED PATHS "/opt/intel/oneapi/mkl/2023.2.0/lib")

add_executable(singleCoreGEMM_BMmkl src/main.cpp)
target_link_libraries(singleCoreGEMM_BMmkl PUBLIC MKL::MKL)