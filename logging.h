#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
// small cleanup
#include <string>

class Logging {
public:
    static void init();
    static void log(const std::string& message, const std::string& level);
// was easier to read this way
};

#define LOG_INFO(message) Logging::log(message, "INFO")
#define LOG_ERROR(message) Logging::log(message, "ERROR")

#endif // LOGGING_H