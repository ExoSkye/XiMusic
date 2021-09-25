file(GLOB impls LIST_DIRECTORIES true CONFIGURE_DEPENDS src/implementations/*)

foreach(impl ${impls})
    cmake_path(GET impl FILENAME impl_name)
    message("Found implementation: ${impl_name}")

    if(USE_${impl_name}_PLAYER)
        include(${impl}/player.cmake)
    endif()

    if(USE_${impl_name}_EFFECT)
        include(${impl}/effect.cmake)
    endif()
endforeach()