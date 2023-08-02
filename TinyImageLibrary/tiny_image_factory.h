#pragma once

#include <memory>
#include "TinyImageLibrary/tiny_image_interface.h"

namespace tiny_image {

    // A list of APIs that TinyImage can use.
    enum class LibraryEnum {
        OPEN_CV,
        OPEN_GL,
    };

    // A factory to create a TinyImageInterface object.
    std::unique_ptr<TinyImageInterface> CreateTinyImage(
        LibraryEnum library_enum);

} // End namespace tiny_image.
