cmake_minimum_required(VERSION 3.19)
project(IntentRecognizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(IntentRecognizer src/main.cpp src/TextAnalyser.cpp src/TextAnalyser.h hello_test.cpp src/IntentRecognizer.cpp src/IntentRecognizer.h src/StringHelper.cpp src/StringHelper.h)
add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)
