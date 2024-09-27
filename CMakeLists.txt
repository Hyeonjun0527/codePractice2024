cmake_minimum_required(VERSION 3.29)
project(first)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

add_executable(first2_main dijkstra/main.cpp)
add_executable(floyd-Warshall_main floyd-Warshall/main.cpp)
add_executable(first1_main2 first1/main2.cpp
)
add_executable(shortestPath_futureCity shortestPath/futureCity.cpp)
add_executable(shortestPath_telegram shortestPath/telegram.cpp)
add_executable(ProblemSolving_12_okunsu ProblemSolving/12_okunsu.cpp)
add_executable(ProblemSolving_11_SumOfNumbers ProblemSolving/11_SumOfNumbers.cpp)
add_executable(ProblemSolving_13_card ProblemSolving/13_card.cpp)
add_executable(ProblemSolving_40 ProblemSolving/40.cpp)
add_executable(ProblemSolving_37 ProblemSolving/37.cpp)
add_executable(ProblemSolving_38 ProblemSolving/38.cpp)