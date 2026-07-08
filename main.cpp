#include "image_compression_tool.h"
#include "logging.h"

int main(int argc, char* argv[]) {
    // Initialize logging
    Logging::init();

    // Parse command-line arguments
    if (argc != 7) {
        LOG_ERROR("Invalid number of arguments");
        return 1;
    }

    std::string input_file = argv[2];
    std::string output_file = argv[4];
    int quality = std::stoi(argv[6]);

    // Compress the image
    try {
        ImageCompressionTool::compress_image(input_file, output_file, quality);
    } catch (const std::exception& e) {
        LOG_ERROR("Error compressing image: {}", e.what());
        return 1;
    }

    return 0;
}