#include "TinyImageLibrary/tiny_image_factory.h"

#include "TinyImageLibrary/opencv_tiny_image.h"
#include "TinyImageLibrary/opengl_tiny_image.h"

namespace tiny_image {

    std::unique_ptr<TinyImageInterface> CreateTinyImage(
        LibraryEnum library_enum) 
    {
        switch (library_enum) {
        case LibraryEnum::OPEN_CV:
            return std::make_unique<OpenCVTinyImage>();
        case LibraryEnum::OPEN_GL:
            return std::make_unique<OpenGLTinyImage>();
        }
    }

} // End namespace tiny image.
