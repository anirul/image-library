#pragma once

#include <gtest/gtest.h>

#include "TinyImageLibrary/tiny_image_factory.h"
#include "TinyImageLibrary/opencv_tiny_image.h"
#include "TinyImageLibrary/opengl_tiny_image.h"

namespace test {

    class TinyImageLibraryTest : 
        public ::testing::TestWithParam<tiny_image::LibraryEnum> {
    public:
        TinyImageLibraryTest() = default;

    protected:
        std::unique_ptr<tiny_image::TinyImageInterface> interface_;
    };

} // End namespace test.
