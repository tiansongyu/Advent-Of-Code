PROJECT(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


ADD_EXECUTABLE(part1 part1.cpp)
add_executable(part2 part2.cpp)
TARGET_LINK_LIBRARIES(part2 -lasound -lfmt)
TARGET_LINK_LIBRARIES(part1 -lasound -lfmt)
file(COPY ./input.txt DESTINATION ./)

set(CMAKE_CXX_STANDARD 17)