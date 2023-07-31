#include "opencv_tiny_image_test.h"
#include <limits>

namespace test {

TEST_F(OpenCVTinyImageLibraryTest, InitializeTest) {
    EXPECT_FALSE(interface_);
    interface_ = std::make_unique<tiny_image::OpenCVTinyImage>();
    EXPECT_TRUE(interface_);
}

TEST_F(OpenCVTinyImageLibraryTest, OpenFileTest) {
    interface_ = std::make_unique<tiny_image::OpenCVTinyImage>();
    EXPECT_TRUE(interface_);
    EXPECT_NO_THROW(interface_->Open("test.png"));
}

TEST_F(OpenCVTinyImageLibraryTest, SizeFileTest) {
    interface_ = std::make_unique<tiny_image::OpenCVTinyImage>();
    EXPECT_TRUE(interface_);
    EXPECT_NO_THROW(interface_->Open("test.png"));
    auto size = interface_->Size();
    EXPECT_EQ(100, size.x);
    EXPECT_EQ(100, size.y);
}

TEST_F(OpenCVTinyImageLibraryTest, ContentFileTest) {
    interface_ = std::make_unique<tiny_image::OpenCVTinyImage>();
    EXPECT_TRUE(interface_);
    EXPECT_NO_THROW(interface_->Open("test.png"));
    auto ptr = interface_->Data();
    std::uint32_t* int_ptr = reinterpret_cast<std::uint32_t*>(ptr);
    std::uint32_t white_val = int_ptr[0];
    std::uint32_t black_val = int_ptr[50 * 100 + 50];
    EXPECT_EQ(0xffffffff, white_val);
    EXPECT_EQ(0x00000000, black_val);
}

} // End namespace test.
