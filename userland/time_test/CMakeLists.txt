cmake_minimum_required(VERSION 3.8.2)

project(cloudos-time_test CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

include(../../wubwubcmake/warning_settings.cmake)
include(../../wubwubcmake/sanitizers.cmake)
add_sane_warning_flags()

add_executable(time_test time_test.cpp)

install(TARGETS time_test RUNTIME DESTINATION bin)
