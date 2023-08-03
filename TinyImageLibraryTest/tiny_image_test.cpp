#include "tiny_image_test.h"
#include "TinyImageLibrary/tiny_image_factory.h"
#include <limits>

namespace test {

    const std::string kTestImageName = "../../TinyImageLibraryTest/test.png";

     INSTANTIATE_TEST_SUITE_P(
         TinyImageLibraryTestSuite, 
         TinyImageLibraryTest,
         ::testing::Values(tiny_image::LibraryEnum::OPEN_CV));

    TEST_P(TinyImageLibraryTest, InitializeTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        EXPECT_FALSE(interface_);
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
    }

    TEST_P(TinyImageLibraryTest, OpenFileTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
    }

    TEST_P(TinyImageLibraryTest, SizeFileTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto size = interface_->Size();
        EXPECT_EQ(100, size.x);
        EXPECT_EQ(100, size.y);
    }

    TEST_P(TinyImageLibraryTest, ContentFileTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto vec = interface_->Data();
        EXPECT_EQ(100 * 100 * 4, vec.size());
        std::uint8_t white_val = vec[0];
        std::uint8_t black_val = vec[(50 * 100 + 50) * 4];
        EXPECT_EQ(0xff, white_val);
        EXPECT_EQ(0x00, black_val);
    }

    TEST_P(TinyImageLibraryTest, ResizeTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto size = interface_->Size();
        EXPECT_EQ(100, size.x);
        EXPECT_EQ(100, size.y);
        EXPECT_NO_THROW(interface_->Resize({ 50, 50 }));
        size = interface_->Size();
        EXPECT_EQ(50, size.x);
        EXPECT_EQ(50, size.y);
    }

    TEST_P(TinyImageLibraryTest, ResizeContentTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto size = interface_->Size();
        EXPECT_EQ(100, size.x);
        EXPECT_EQ(100, size.y);
        std::uint8_t orig_0_0_val = interface_->Data()[0];
        std::uint8_t orig_50_50_val = interface_->Data()[(50 * 100 + 50) * 4];
        EXPECT_NO_THROW(interface_->Resize({ 50, 50 }));
        size = interface_->Size();
        EXPECT_EQ(50, size.x);
        EXPECT_EQ(50, size.y);
        std::uint8_t resized_0_0_val = interface_->Data()[0];
        std::uint8_t resized_25_25_val = interface_->Data()[(25 * 50 + 25) * 4];
        EXPECT_EQ(orig_0_0_val, resized_0_0_val);
        EXPECT_EQ(orig_50_50_val, resized_25_25_val);
    }

    TEST_P(TinyImageLibraryTest, CropTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto size = interface_->Size();
        EXPECT_EQ(100, size.x);
        EXPECT_EQ(100, size.y);
        EXPECT_NO_THROW(interface_->Crop({ 25, 25, 50, 50 }));
        size = interface_->Size();
        EXPECT_EQ(50, size.x);
        EXPECT_EQ(50, size.y);
    }

    TEST_P(TinyImageLibraryTest, CropContentTest) {
        tiny_image::LibraryEnum library_enum = GetParam();
        interface_ = tiny_image::CreateTinyImage(library_enum);
        EXPECT_TRUE(interface_);
        EXPECT_NO_THROW(interface_->Open(kTestImageName));
        auto size = interface_->Size();
        EXPECT_EQ(100, size.x);
        EXPECT_EQ(100, size.y);
        std::uint8_t orig_25_25_val = interface_->Data()[(25 * 100 + 25) * 4];
        std::uint8_t orig_50_50_val = interface_->Data()[(50 * 100 + 50) * 4];
        EXPECT_NO_THROW(interface_->Crop({ 25, 25, 50, 50 }));
        size = interface_->Size();
        EXPECT_EQ(50, size.x);
        EXPECT_EQ(50, size.y);
        std::uint8_t cropped_0_0_val = interface_->Data()[0];
        std::uint8_t cropped_25_25_val = interface_->Data()[(25 * 50 + 25) * 4];
        EXPECT_EQ(orig_25_25_val, cropped_0_0_val);
        EXPECT_EQ(orig_50_50_val, cropped_25_25_val);
    }

} // End namespace test.
