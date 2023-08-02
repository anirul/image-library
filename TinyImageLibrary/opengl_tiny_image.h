#pragma once

#include <glm/glm.hpp>

#include "TinyImageLibrary/tiny_image_interface.h"

namespace tiny_image {

    class OpenGLTinyImage : public TinyImageInterface {
    public:
        OpenGLTinyImage() = default;
        ~OpenGLTinyImage() override = default;

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
    };

} // End namespace tiny_image.
