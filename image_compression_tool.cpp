#include "image_compression_tool.h"
#include "image_utils.h"
#include <stb_image.h>
#include <stb_image_write.h>

void ImageCompressionTool::compress_image(const std::string& input_file, const std::string& output_file, int quality) {
    // Load the input image
    int width, height, channels;
    unsigned char* data = stbi_load(input_file.c_str(), &width, &height, &channels, 0);
    if (!data) {
        throw std::runtime_error("Failed to load input image");
    }

    // Compress the image
    ImageUtils::compress_image_data(data, width, height, channels, quality);

    // Save the compressed image
    if (!stbi_write_jpg(output_file.c_str(), width, height, channels, data)) {
        throw std::runtime_error("Failed to save compressed image");
    }

    // Free the image data
    stbi_image_free(data);
}