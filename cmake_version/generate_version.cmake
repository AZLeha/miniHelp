get_filename_component(SRC_DIR ${SRC} DIRECTORY)

find_package(Git)

if(((NOT DEFINED TEST_VERSION) OR (NOT TEST_VERSION)) AND GIT_EXECUTABLE)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --abbrev=4 --tags --dirty --match "v*"
        WORKING_DIRECTORY ${SRC_DIR}
        OUTPUT_VARIABLE TEST_VERSION
        RESULT_VARIABLE GIT_DESCRIBE_ERROR_CODE
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
endif()

if((NOT DEFINED TEST_VERSION) OR (NOT TEST_VERSION) OR GIT_DESCRIBE_ERROR_CODE)
    set(TEST_VERSION "v0.0.0-unknown")
    message(WARNING "Failed to get version description from repository, use default instead.")
endif()

configure_file(${SRC} ${DST} @ONLY)
