include(FetchContent)

FetchContent_Declare(dr_libs
        GIT_REPOSITORY     https://github.com/mackron/dr_libs
        GIT_SHALLOW        TRUE
        SOURCE_DIR         ${CMAKE_BINARY_DIR}/dr_libs)

FetchContent_GetProperties(dr_libs)

if(NOT dr_libs_POPULATED)
    message(STATUS "Fetching dr_libs")
    FetchContent_Populate(dr_libs)
    message(STATUS "Fetched dr_libs")
endif()

target_include_directories(XiMusic PRIVATE ${dr_libs_SOURCE_DIR})
target_sources(XiMusic PRIVATE PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dr_libs.c)