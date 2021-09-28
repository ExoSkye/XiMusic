cmake_minimum_required(VERSION 3.20)
project(XiMusic LANGUAGES C)

set(CMAKE_C_STANDARD 11)

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

include(docs/docs.cmake)

include(depends/sds.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(XiMusic src/main.c src/audioPlayer.h src/audioEffect.h src/audioLoader.h src/audioResampler.h)
target_include_directories(XiMusic PRIVATE src)
target_link_libraries(XiMusic PRIVATE sds-lib libfar-interface)

include(preset-handler.cmake)
include(implementation-handler.cmake)