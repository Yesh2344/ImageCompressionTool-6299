cmake_minimum_required(VERSION 3.10)
project(ImageCompressionTool)

add_executable(${PROJECT_NAME} main.cpp image_compression_tool.cpp image_utils.cpp logging.cpp)
target_link_libraries(${PROJECT_NAME} stb_image stb_image_write jpeg)

enable_testing()
add_executable(test_image_compression_tool test_image_compression_tool.cpp)
target_link_libraries(test_image_compression_tool image_compression_tool)
add_test(NAME test_image_compression_tool COMMAND test_image_compression_tool)
