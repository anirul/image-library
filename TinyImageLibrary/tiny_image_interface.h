#pragma once

#include <string_view>
#include <glm/glm.hpp>

namespace tiny_image {

    // Tiny image interface.
    // This is the interface to access an image an do basic modifications.
    struct TinyImageInterface {
        // Virtual destructor to avoid problem backward destructor call.
        virtual ~TinyImageInterface() = default;
        // Get the size of the loaded image.
        virtual glm::uvec2 Size() const = 0;
        // Get a pointer to the content of the image.
        virtual void* Data() const = 0;

        // This is the interface that is asked.
        // Open a file from the disk to the image.
        virtual void Open(std::string_view filename) = 0;
        // Save a file to the disk from the image.
        virtual void Save(std::string_view filename) = 0;
        // Resize the image to match a new one, warning you cannot increase
        // the size!
        virtual void Resize(glm::uvec2 size) = 0;
        // Crop the image to a new size (this should be included in the
        // current image).
        virtual void Crop(glm::uvec4 rect) = 0;
    };

} // namespace tiny_image
