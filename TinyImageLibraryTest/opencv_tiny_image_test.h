#pragma once

#include <gtest/gtest.h>

#include "TinyImageLibrary/opencv_tiny_image.h"

namespace test {

    class OpenCVTinyImageLibraryTest : public ::testing::Test {
    public:
        OpenCVTinyImageLibraryTest() = default;

    protected:
        std::unique_ptr<tiny_image::TinyImageInterface> interface_;
    };

} // End namespace test.
