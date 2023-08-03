#pragma once

#include <glm/glm.hpp>

#include <vector>

#include "TinyImageLibrary/tiny_image_interface.h"
#include "submodules/Frame/include/frame/image_interface.h"
#include "submodules/Frame/include/frame/texture_interface.h"

namespace tiny_image {

    class OpenGLTinyImage : public TinyImageInterface {
    public:
        OpenGLTinyImage() = default;
        ~OpenGLTinyImage() override = default;

        // External interface.
        glm::uvec2 Size() const override;
        std::vector<std::uint8_t> Data() const override;
        std::unique_ptr<TinyImageInterface> Clone() const override;
        void Copy(const TinyImageInterface* other) override;

        // Internal interface.
        void Open(std::string_view filename) override;
        void Save(std::string_view filename) override;
        void Resize(glm::uvec2 size) override;
        void Crop(glm::uvec4 rect) override;

    private:
        std::unique_ptr<frame::ImageInterface> image_;
        std::unique_ptr<frame::TextureInterface> texture_;
    };

} // End namespace tiny_image.
