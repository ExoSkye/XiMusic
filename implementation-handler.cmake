file(GLOB impls LIST_DIRECTORIES true CONFIGURE_DEPENDS src/implementations/*)

foreach(impl ${impls})
    cmake_path(GET impl FILENAME impl_name)
    message("Found implementation: ${impl_name}")

    if(USE_${impl_name}_PLAYER)
        include(${impl}/player.cmake)
        message("Using ${impl_name} player")
    endif()

    if(USE_${impl_name}_EFFECT)
        include(${impl}/effect.cmake)
        message("Using ${impl_name} effects")
    endif()

    if(USE_${impl_name}_PARSER)
        include(${impl}/parser.cmake)
        message("Using ${impl_name} for audio file parsing")
    endif()
endforeach()