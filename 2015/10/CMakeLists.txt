PROJECT(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


add_executable(part1 part1.cpp)

set_target_properties(part1 PROPERTIES CXX_STANDARD 17)

file(COPY ./input.txt DESTINATION ./)

if (${APPLE})


find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_fmt REQUIRED IMPORTED_TARGET fmt)
include_directories(${PKG_fmt_INCLUDE_DIRS})
target_link_libraries (part1 ${PKG_fmt_LDFLAGS})

else()

target_link_libraries (part1 -lfmt)
endif()



