add_executable(zoom_app
    main.cpp
)

target_include_directories(zoom_app
    PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(zoom_app
    PRIVATE
        tiny_image_library
        absl::base
        absl::flags
        absl::flags_parse
        absl::strings
)

set_property(TARGET zoom_app PROPERTY FOLDER "ZoomApp")
