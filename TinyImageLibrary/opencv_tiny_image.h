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
        void Resize(int width, int height) override;
        void Crop(int x, int y, int width, int height) override;
        std::tuple<int, int> Size() const override;
        
    protected:
        cv::Mat img_;
    };

}  // End namespace tiny_image.
