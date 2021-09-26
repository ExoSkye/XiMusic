find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_PULSEAUDIO libpulse)

find_path(PULSEAUDIO_INCLUDE_DIR pulse/pulseaudio.h HINTS ${PC_PULSEAUDIO_INCLUDEDIR} ${PC_PULSEAUDIO_INCLUDE_DIRS})
find_library(PULSEAUDIO_LIBRARY NAMES pulse HINTS ${PC_PULSEAUDIO_LIBDIR} ${PC_PULSEAUDIO_LIBRARY_DIRS})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PulseAudio DEFAULT_MSG PULSEAUDIO_LIBRARY PULSEAUDIO_INCLUDE_DIR)

mark_as_advanced(PULSEAUDIO_INCLUDE_DIR PULSEAUDIO_LIBRARY)

target_sources(XiMusic PRIVATE ${CMAKE_CURRENT_LIST_DIR}/pulseaudioPlayer.c)
target_link_libraries(XiMusic PRIVATE ${PULSEAUDIO_LIBRARY} pulse-simple)
target_include_directories(XiMusic PRIVATE ${PULSEAUDIO_INCLUDE_DIR})