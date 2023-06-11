cmake_minimum_required(VERSION 3.20)
project(largeNumber_calculation)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
include_directories(D:\\clion tect\\largeNumber_calculation\\include)
link_libraries(Psapi.Lib)

add_executable(largeNumber_calculation main.cpp src/jianFa.cpp src/jiaFa.cpp src/chengFa.cpp src/chuFa.cpp)
