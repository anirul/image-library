#pragma once

#include <string_view>

namespace tiny_image {

    struct TinyImageInterface {
        virtual ~TinyImageInterface() = default;
        virtual void Open(std::string_view filename) = 0;
        virtual void Save(std::string_view filename) = 0;
        virtual void Resize(int width, int height) = 0;
        virtual void Crop(int x, int y, int width, int height) = 0;
        virtual std::tuple<int, int> Size() const = 0;
    };

} // namespace tiny_image
