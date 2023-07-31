#include "TinyImageLibrary/opencv_tiny_image.h"

#include <stdexcept>

namespace tiny_image {

    void OpenCVTinyImage::Open(std::string_view filename)
    {
        img_ = cv::imread(filename.data(), cv::IMREAD_COLOR);
        if (img_.empty()) {
            throw std::runtime_error("Failed to open image.");
        }
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
