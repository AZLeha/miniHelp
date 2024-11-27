cmake_minimum_required(VERSION 3.24)
project(examples LANGUAGES C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../)

add_executable(${PROJECT_NAME}
    ./main.c
)

target_link_libraries(${PROJECT_NAME}  PRIVATE LibLog)
