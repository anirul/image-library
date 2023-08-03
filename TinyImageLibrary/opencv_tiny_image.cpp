#include "TinyImageLibrary/opencv_tiny_image.h"

#include <stdexcept>
#include <iostream>
#include <format>

namespace tiny_image {

    void OpenCVTinyImage::Open(std::string_view filename)
    {
        img_ = cv::imread(filename.data(), cv::IMREAD_COLOR);
        if (img_.empty() || img_.cols == 0) {
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
        // Convert the image to a continuous image to avoid problems with the
        // image.step != size.y.
        cv::Mat continuousImage = img_.clone();
        img_ = continuousImage;
    }

    glm::uvec2 OpenCVTinyImage::Size() const
    {
        return { img_.cols, img_.rows };
    }

    std::vector<std::uint8_t> OpenCVTinyImage::Data() const
    {
        std::vector<std::uint8_t> data;
        data.resize(Size().x * Size().y * 4);
        std::memcpy(data.data(), img_.data, data.size());
        return data;
    }

    std::unique_ptr<tiny_image::TinyImageInterface> 
        OpenCVTinyImage::Clone() const
    {
        auto clone = std::make_unique<OpenCVTinyImage>();
        clone->img_ = img_.clone();
        return clone;
    }

    void OpenCVTinyImage::Copy(const TinyImageInterface* other)
    {
        const auto* opencv_ptr = dynamic_cast<const OpenCVTinyImage*>(other);
        img_ = opencv_ptr->img_.clone();
    }

} // End namespace tiny image.
