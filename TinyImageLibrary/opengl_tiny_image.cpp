#include "TinyImageLibrary/opengl_tiny_image.h"

namespace tiny_image {

    glm::uvec2 OpenGLTinyImage::Size() const
    {
        return { 0, 0 };
    }

    void* OpenGLTinyImage::Data() const
    {
        return nullptr;
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
