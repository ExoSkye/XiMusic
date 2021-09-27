file(GLOB presets LIST_DIRECTORIES true CONFIGURE_DEPENDS presets/*)


foreach(preset_path ${presets})
    cmake_path(GET preset_path FILENAME preset_name)
    message("Found preset: ${preset_name}")

    if(PRESET STREQUAL ${preset_name})
        include(${preset_path}/preset.cmake)
        message("Using preset: ${preset_name}")
    endif()
endforeach()