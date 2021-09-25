cmake_minimum_required(VERSION 3.20)
project(XiMusic LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include(docs/docs.cmake)

include(depends/sds.cmake)

add_executable(XiMusic src/main.c src/audioPlayer.h src/audioEffect.h src/implementations/SDL/SDLMixerPlayer.c src/implementations/defaultEffectEngine.c)
target_include_directories(XiMusic PRIVATE src)
target_link_libraries(XiMusic PRIVATE sds-lib)
