#include "TinyImageLibrary/opencv_tiny_image.h"

namespace tiny_image {

    void OpenCVTinyImage::Open(std::string_view filename)
    {
        img_ = cv::imread(filename.data(), cv::IMREAD_COLOR);
    }

    void OpenCVTinyImage::Save(std::string_view filename)
    {
        cv::imwrite("output.jpg", img_);
    }

    void OpenCVTinyImage::Resize(int width, int height)
    {
        cv::resize(img_, img_, cv::Size(width, height));
    }

    void OpenCVTinyImage::Crop(int x, int y, int width, int height)
    {
        cv::Rect roi(x, y, width, height);
        img_ = img_(roi);
    }

    std::tuple<int, int> OpenCVTinyImage::Size() const
    {
        return { img_.cols, img_.rows };
    }

} // End namespace tiny image.
