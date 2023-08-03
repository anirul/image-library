#include "TinyImageLibrary/opengl_tiny_image.h"

namespace tiny_image {

    glm::uvec2 OpenGLTinyImage::Size() const
    {
        return texture_->GetSize();
    }

    std::vector<std::uint8_t> OpenGLTinyImage::Data() const
    {
        return std::move(texture_->GetTextureByte());
    }

    std::unique_ptr<tiny_image::TinyImageInterface> 
        OpenGLTinyImage::Clone() const
    {
        return std::make_unique<OpenGLTinyImage>();
    }

    void OpenGLTinyImage::Copy(const TinyImageInterface* other)
    {

    }

    void OpenGLTinyImage::Open(std::string_view filename)
    {

    }

    void OpenGLTinyImage::Save(std::string_view filename)
    {

    }

    void OpenGLTinyImage::Resize(glm::uvec2 size)
    {

    }

    void OpenGLTinyImage::Crop(glm::uvec4 rect)
    {

    }

}  // End namespace tiny_image.
