cmake_minimum_required(VERSION 3.20)
project(XiMusic LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include(docs/docs.cmake)

include(depends/sds.cmake)

add_executable(XiMusic src/main.c src/audioPlayer.h src/audioEffect.h)
target_link_libraries(XiMusic PRIVATE sds-lib)
