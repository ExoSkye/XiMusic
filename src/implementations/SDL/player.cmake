find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

target_sources(XiMusic PRIVATE ${CMAKE_CURRENT_LIST_DIR}/SDLMixerPlayer.c)
target_link_libraries(XiMusic PRIVATE SDL2::Mixer)