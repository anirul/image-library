#pragma once

#include "TinyImageLibrary/tiny_image_interface.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace tiny_image {

    class OpenCVTinyImage : public TinyImageInterface {
    public:
        OpenCVTinyImage() = default;
        ~OpenCVTinyImage() override = default;
        void Open(std::string_view filename) override;
        void Save(std::string_view filename) override;
        void Resize(glm::uvec2 size) override;
        void Crop(glm::uvec4 rect) override;
        glm::uvec2 Size() const override;
        void* Data() const override;
        
    protected:
        cv::Mat img_;
    };

}  // End namespace tiny_image.
