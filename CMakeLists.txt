cmake_minimum_required(VERSION 3.24)
project(BuildSystems LANGUAGES CXX)


add_subdirectory (./LibLog)

message(${CMAKE_SYSTEM_NAME})

if(WIN32)       # windows
elseif(APPLE)   # MacOSX
else()          # Linux
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")    # windows
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin") # MacOSX
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")  # Linux
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ./LibLog
)

set(PROJECT_SOURCES
    main.cpp

)


add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME}  PRIVATE LibLog)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/out)
file(COPY DESTINATION ${EXECUTABLE_OUTPUT_PATH})


add_custom_target(
    version
    ${CMAKE_COMMAND} -D SRC=${CMAKE_SOURCE_DIR}/cmake_version/version.h.in
    -D DST=${CMAKE_BINARY_DIR}/version/version.h
    -D CUBIOS_VERSION=${CUBIOS_VERSION}
    -P ${CMAKE_SOURCE_DIR}/cmake_version/generate_version.cmake
)

include_directories(${CMAKE_BINARY_DIR}/version)
add_dependencies(${CMAKE_PROJECT_NAME} version)
