#include "logging.h"

void Logging::init() {
    // Initialize the logging system
}

void Logging::log(const std::string& message, const std::string& level) {
    std::cout << "[" << level << "] " << message << std::endl;
}