PROJECT(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


add_executable(part2 part2.cpp)

set_target_properties(part2 PROPERTIES CXX_STANDARD 17)

file(COPY ./input.txt DESTINATION ./)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_fmt REQUIRED IMPORTED_TARGET fmt)

include_directories(${PKG_fmt_INCLUDE_DIRS})
target_link_libraries (part2 ${PKG_fmt_LDFLAGS})

