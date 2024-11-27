cmake_minimum_required(VERSION 3.24)
project(LibTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




find_package(CxxTest)

include_directories (../)

if(CXXTEST_FOUND)
  include_directories(${CXXTEST_INCLUDE_DIR})
  enable_testing()
  CXXTEST_ADD_TEST(${PROJECT_NAME} foo_test.cc
                   ${CMAKE_CURRENT_SOURCE_DIR}/tst_LibLog.h)
  target_link_libraries(${PROJECT_NAME} LibLog)

endif()


