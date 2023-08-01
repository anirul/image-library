#include "TinyImageLibrary/opencv_tiny_image.h"

#include <stdexcept>
#include <iostream>
#include <format>

namespace tiny_image {

    void OpenCVTinyImage::Open(std::string_view filename)
    {
        img_ = cv::imread(filename.data(), cv::IMREAD_COLOR);
        if (img_.empty()) {
            throw std::runtime_error("Failed to open image.");
        }
        // Look if this is a 3 color image and convert it to RGB.
        if (img_.channels() == 3 && img_.depth() == CV_8U) {
            cv::cvtColor(img_, img_, cv::COLOR_BGR2RGBA);
        }
        // Look if this is a 4 color image and convert it to RGB.
        else if (img_.channels() == 4 && img_.depth() == CV_8U) {
            cv::cvtColor(img_, img_, cv::COLOR_BGRA2RGBA);
        }
        else {
            throw std::runtime_error(
                std::format(
                    "Not a valid format channels {} and depth {}",
                    img_.channels(),
                    img_.depth()));
        }
        // Flip the image to match the OpenGL coordinate system.
        cv::flip(img_, img_, 0);
    }

    void OpenCVTinyImage::Save(std::string_view filename)
    {
        cv::imwrite("output.jpg", img_);
    }

    void OpenCVTinyImage::Resize(glm::uvec2 size)
    {
        cv::resize(img_, img_, cv::Size(size.x, size.y));
    }

    void OpenCVTinyImage::Crop(glm::uvec4 rect)
    {
        cv::Rect roi(rect.x, rect.y, rect.z, rect.w);
        img_ = img_(roi);
    }

    glm::uvec2 OpenCVTinyImage::Size() const
    {
        return { img_.cols, img_.rows };
    }

    void* OpenCVTinyImage::Data() const
    {
        return static_cast<void*>(img_.data);
    }

} // End namespace tiny image.
