# Tiny Image library
add_library(tiny_image_library
    STATIC
        tiny_image_factory.cpp
        tiny_image_factory.h
        tiny_image_interface.h
        opengl_tiny_image.cpp
        opengl_tiny_image.h
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
        opencv_highgui 
        opencv_imgcodecs 
        opencv_imgproc
)

set_property(TARGET tiny_image_library PROPERTY FOLDER "TinyImageLibrary")
