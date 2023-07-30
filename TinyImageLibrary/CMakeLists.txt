# Tiny Image library
add_library(tiny_image_library
    STATIC
        tiny_image_interface.h
        opencv_tiny_image.cpp
        opencv_tiny_image.h
)

target_include_directories(tiny_image_library
    PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(tiny_image_library 
    PRIVATE 
        glm::glm
        opencv_core
)

set_property(TARGET tiny_image_library PROPERTY FOLDER "TinyImageLibrary")
