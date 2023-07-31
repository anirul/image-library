
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>

#include <iostream>
#include <format>
#include <memory>

#include "TinyImageLibrary/opencv_tiny_image.h"

ABSL_FLAG(std::string, input_file, "", "Input file image to be process.");
ABSL_FLAG(std::string, output_file, "", "Output file image to be saved.");

int main(int ac, char** av) try {
    absl::ParseCommandLine(ac, av);
    auto interface = std::make_unique<tiny_image::OpenCVTinyImage>();
    if (absl::GetFlag(FLAGS_input_file).empty()) {
           std::cerr << "Error: input_file or output_file is empty.\n";
           return 1;
       }
    interface->Open(absl::GetFlag(FLAGS_input_file));

    if (absl::GetFlag(FLAGS_output_file).empty()) {
        std::cerr << "Error: input_file or output_file is empty.\n";
    } else {
        interface->Save(absl::GetFlag(FLAGS_output_file));
    }
    return 0;
} catch (std::exception& ex) {
    std::cerr << std::format("Exception: {}\n", ex.what());
    return 1;
}
