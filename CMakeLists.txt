cmake_minimum_required(VERSION 3.10)
project(mfile
  LANGUAGES CXX
  VERSION 0.1.0
  DESCRIPTION "memory mapped file"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

file(GLOB EXEC_SRC "src/*.cpp")
add_library(mfile STATIC ${EXEC_SRC})
add_compile_options(-Wall -Wextra -Wpedantic -Werror)
include_directories(src/)

pkg_check_modules(GTEST gtest)
if (GTEST_FOUND)
  enable_testing()
  file(GLOB TEST_SRC "tests/*")

  add_executable(unit ${TEST_SRC} $<FILTER:${EXEC_SRC},EXCLUDE,main.cpp>)

  target_link_libraries(unit PRIVATE ${GTEST_LDFLAGS})
  target_compile_options(unit PRIVATE ${GTEST_CFLAGS})
  add_test(unit unit)
endif()

install(TARGETS mfile RUNTIME DESTINATION lib)
# install(FILES docs/git-each.1 DESTINATION share/man/man1)
# install(FILES docs/git-each-format.5 DESTINATION share/man/man5)
