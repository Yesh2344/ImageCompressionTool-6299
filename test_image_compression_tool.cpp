#include "image_compression_tool.h"
#include "gtest/gtest.h"

TEST(ImageCompressionToolTest, CompressImage) {
    // Test the image compression tool
    ImageCompressionTool::compress_image("input_image.jpg", "output_image.jpg", 90);

    // Check the output image file
    ASSERT_TRUE(std::filesystem::exists("output_image.jpg"));
}