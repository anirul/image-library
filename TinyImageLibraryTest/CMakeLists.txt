add_executable(tiny_image_library_test
    main.cpp
    tiny_image_test.cpp
    tiny_image_test.h
)

target_include_directories(tiny_image_library_test
    PUBLIC
        ${CMAKE_SOURCE_DIR}/TinyImageLibrary
        ${CMAKE_SOURCE_DIR}/TestTinyImageLibrary
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(tiny_image_library_test
    PRIVATE
        tiny_image_library
        GTest::gtest
        glm::glm
)

include(GoogleTest)
gtest_add_tests(TARGET tiny_image_library_test)

set_property(TARGET tiny_image_library_test PROPERTY FOLDER "TinyImageLibraryTest")
