cmake_minimum_required(VERSION 3.19)
project(aoc_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc_cpp main.cpp Days/Day01/Elevator.cpp Days/Day01/Elevator.h Days/Day01/ElevatorInstructor.cpp Days/Day01/ElevatorInstructor.h Days/Day01/Day01.cpp Days/Day01/Day01.h Days/Day01/BasementElevatorInstructor.cpp Days/Day01/BasementElevatorInstructor.h Days/Day.cpp Days/Day.h Days/Day02/Day02.cpp Days/Day02/Day02.h Days/Day02/Box.h Days/Day02/Box.cpp Days/Day03/Day03.cpp Days/Day03/Day03.h Days/Day03/Traveller.cpp Days/Day03/Traveller.h Days/Day04/Day04.cpp Days/Day04/Day04.h Days/Day05/Day05.cpp Days/Day05/Day05.h Days/Day06/Day06.cpp Days/Day06/Day06.h Days/Day07/Day07.cpp Days/Day07/Day07.h)

find_package(CryptoPP CONFIG REQUIRED)
target_link_libraries(aoc_cpp PRIVATE cryptopp-static)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(aoc_cpp PUBLIC -DDEBUG=1)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(aoc_cpp PUBLIC -DDEBUG=0)
    target_compile_definitions(aoc_cpp PUBLIC -DRUN_BRUTE_FORCE_DAYS=1)
endif()

FILE(COPY inputs DESTINATION "${CMAKE_BINARY_DIR}")