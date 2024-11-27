cmake_minimum_required(VERSION 3.24)
project(LibLog LANGUAGES C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    ./log.c
)

include_directories(./)

add_library( ${PROJECT_NAME} STATIC
    ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ./include
)


if(${PROJECT_IS_TOP_LEVEL})
    add_subdirectory(./example)
    add_subdirectory(./tests)
endif(${PROJECT_IS_TOP_LEVEL})


# Указываем папку, куда будут установлены файлы библиотеки
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION LibLog
        LIBRARY DESTINATION LibLog
        RUNTIME DESTINATION bin)
install(FILES LibLog/log.h DESTINATION include)
