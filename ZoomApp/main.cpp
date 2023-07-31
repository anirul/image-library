
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>

#include <iostream>
#include <format>
#include <memory>

#include "TinyImageLibrary/opencv_tiny_image.h"

int main(int ac, char** av) try {
    auto interface = std::make_unique<tiny_image::OpenCVTinyImage>();
    return 0;
} catch (std::exception& ex) {
    std::cerr << std::format("Exception: {}\n", ex.what());
    return 1;
}
