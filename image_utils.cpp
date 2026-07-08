#include "image_utils.h"
#include <jpeglib.h>

void ImageUtils::compress_image_data(unsigned char* data, int width, int height, int channels, int quality) {
    // Create a JPEG compressor
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    // Set the image parameters
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = channels;
    cinfo.in_color_space = JCS_RGB;

    // Set the quality level
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE);

    // Compress the image data
    jpeg_start_compress(&cinfo, TRUE);

    // Write the compressed image data
    JSAMPROW row_pointer[1];
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] = &data[cinfo.next_scanline * cinfo.image_width * cinfo.input_components];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    // Finish the compression
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
}