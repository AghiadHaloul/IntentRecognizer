cmake_minimum_required(VERSION 3.21)
project(IntentRecognizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(IntentRecognizer main.cpp TextAnalyser.cpp TextAnalyser.h)
