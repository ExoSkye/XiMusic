if (NOT WIN32)
    message(FATAL_ERROR "You aren't on windows so you can't use WASAPI")
else()
    include(CheckIncludeFile)
    check_include_file(audioclient.h AUDIOCLIENT_H)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WASAPI DEFAULT_MSG AUDIOCLIENT_H)

target_sources(XiMusic PRIVATE ${CMAKE_CURRENT_LIST_DIR}/wasapiPlayer.c)