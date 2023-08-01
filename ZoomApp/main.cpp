
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>

#include <iostream>
#include <format>
#include <memory>

// From: https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "frame/common/application.h"
#include "frame/file/file_system.h"
#include "frame/file/image_stb.h"
#include "frame/gui/draw_gui_factory.h"
#include "frame/gui/input_factory.h"
#include "frame/gui/window_camera.h"
#include "frame/gui/window_cubemap.h"
#include "frame/gui/window_resolution.h"
#include "frame/json/parse_json.h"
#include "frame/json/parse_level.h"
#include "frame/json/proto.h"
#include "frame/window_factory.h"
#include "TinyImageLibrary/opencv_tiny_image.h"

ABSL_FLAG(std::string, input_file, "", "Input file image to be process.");
ABSL_FLAG(std::string, json_file, "", "JSON file for the windowing system.");
ABSL_FLAG(std::string, output_file, "", "Output file image to be saved.");

void DrawWindow(tiny_image::TinyImageInterface* tiny_image_interface) {
    frame::common::Application app(
    frame::CreateNewWindow(
        frame::DrawingTargetEnum::WINDOW,
        frame::RenderingAPIEnum::OPENGL,
        { 1280, 720 }));
    // Now load the JSON file into a level.
    auto level = frame::proto::ParseLevel(
        { 1280, 720 },
        frame::file::FindFile(absl::GetFlag(FLAGS_json_file)));
    auto* level_ptr = level.get();
    // Start the application load.
    app.Startup(std::move(level));
    app.Run([&tiny_image_interface, &level_ptr] {
        for (auto id : level_ptr->GetAllTextures()) {
            auto& texture = level_ptr->GetTextureFromId(id);
            auto name = texture.GetName();
            if (name == "tiny_image") {
                const glm::uvec2 size = tiny_image_interface->Size();
                // FIXME(anirul): Bad copy this should be avoided in the future.
                std::vector<uchar> data(size.x * size.y * 4);
                std::memcpy(
                    data.data(),
                    tiny_image_interface->Data(),
                    data.size());
                texture.Update(std::move(data), size, 4);
            }
        }
    });
}

int main(int ac, char** av) try {
    absl::ParseCommandLine(ac, av);
    std::unique_ptr<tiny_image::TinyImageInterface> tiny_image_interface =
        std::make_unique<tiny_image::OpenCVTinyImage>();
    if (absl::GetFlag(FLAGS_input_file).empty()) {
        std::cerr << "Error: input_file is empty.\n";
        return 1;
    }
    if (absl::GetFlag(FLAGS_json_file).empty()) {
        std::cerr << "Error: json_file is empty.\n";
        return 1;
    }
    tiny_image_interface->Open(absl::GetFlag(FLAGS_input_file));
    DrawWindow(tiny_image_interface.get());
    if (absl::GetFlag(FLAGS_output_file).empty()) {
        std::cerr <<
            "Error: output_file is empty the modification won't be saved.\n";
    }
    else {
        tiny_image_interface->Save(absl::GetFlag(FLAGS_output_file));
    }
    return 0;
}
catch (std::exception& ex) {
    std::cerr << std::format("Exception: {}\n", ex.what());
    return 1;
}
