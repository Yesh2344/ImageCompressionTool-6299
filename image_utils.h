#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <string>

class ImageUtils {
public:
    static void compress_image_data(unsigned char* data, int width, int height, int channels, int quality);
};

#endif // IMAGE_UTILS_H