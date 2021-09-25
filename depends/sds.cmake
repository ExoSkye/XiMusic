include(FetchContent)

FetchContent_Declare(sds
        GIT_REPOSITORY  https://github.com/antirez/sds.git
        GIT_TAG         2.0.0
        GIT_SHALLOW     TRUE
        SOURCE_DIR      ${CMAKE_BINARY_DIR}/sds
        )

FetchContent_GetProperties(sds)
if(NOT sds_POPULATED)
    message(STATUS "Fetching Simple Dynamic Strings")
    FetchContent_Populate(sds)
    message(STATUS "Fetched Simple Dynamic Strings")
endif()

add_library(sds ${sds_SOURCE_DIR}/sds.c ${sds_SOURCE_DIR}/sds.h ${sds_SOURCE_DIR}/sdsalloc.h)

add_library(sds-lib INTERFACE)
target_include_directories(sds-lib INTERFACE ${sds_SOURCE_DIR})
target_link_libraries(sds-lib INTERFACE sds)