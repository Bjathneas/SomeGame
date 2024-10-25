//
// Created by benajah on 10/17/24.
//
#include "bEngine/Utils/Logger.h"

#include <cstdio>
#include <ctime>
#include <filesystem>

namespace bEngine::Utils {
    void debug(const char* file, int line, const char* message) {
        log("DEBUG", file, line, message);
    }

    void info(const char* file, int line, const char* message) {
        log("INFO", file, line, message);
    }

    void warn(const char* file, int line, const char* message) {
        log("WARNING", file, line, message);
    }

    void error(const char* file, int line, const char* message) {
        log("ERROR", file, line, message);
    }

    void log(const char* level, const char* file, int line, const char* message) {
        std::time_t time = std::time(nullptr);
        std::filesystem::path path(file);
        std::printf("[%.24s] [%s] %s:%i -> %s\n", ctime(&time), level, path.filename().c_str(), line, message);
    }
}// namespace bEngine::Utils