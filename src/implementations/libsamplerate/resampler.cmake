include(FetchContent)

FetchContent_Declare(samplerate
        GIT_REPOSITORY  https://github.com/libsndfile/libsamplerate.git
        GIT_TAG         0.2.2
        GIT_SHALLOW     TRUE
        SOURCE_DIR      ${CMAKE_BINARY_DIR}/libsamplerate
)

FetchContent_GetProperties(samplerate)
if(NOT samplerate_POPULATED)
    message(STATUS "Fetching libsamplerate")
    FetchContent_Populate(samplerate)
    message(STATUS "Fetched libsamplerate")
endif()

add_subdirectory(${samplerate_SOURCE_DIR})

target_include_directories(XiMusic PRIVATE ${samplerate_SOURCE_DIR}/include)
target_link_libraries(XiMusic PRIVATE samplerate)
target_sources(XiMusic PRIVATE ${CMAKE_CURRENT_LIST_DIR}/libsamplerateResampler.c)