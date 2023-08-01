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

        // External interface.
        glm::uvec2 Size() const override;
        void* Data() const override;
        std::unique_ptr<TinyImageInterface> Clone() const override;
        void Copy(const TinyImageInterface* other) override;

        // Internal interface.
        void Open(std::string_view filename) override;
        void Save(std::string_view filename) override;
        void Resize(glm::uvec2 size) override;
        void Crop(glm::uvec4 rect) override;
        
    protected:
        cv::Mat img_;
    };

}  // End namespace tiny_image.
