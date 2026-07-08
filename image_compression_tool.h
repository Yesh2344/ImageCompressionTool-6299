#ifndef IMAGE_COMPRESSION_TOOL_H
#define IMAGE_COMPRESSION_TOOL_H

#include <string>

class ImageCompressionTool {
public:
    static void compress_image(const std::string& input_file, const std::string& output_file, int quality);
};

#endif // IMAGE_COMPRESSION_TOOL_H