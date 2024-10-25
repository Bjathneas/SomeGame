//
// Created by benajah on 10/17/24.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#ifndef DEBUG_MODE
#define DEBUG(message)
#else
#define DEBUG(message) \
    bEngine::Utils::debug(__FILE__, __LINE__, message);
#endif//DEBUG_MODE

#define INFO(message) \
    bEngine::Utils::info(__FILE__, __LINE__, message);
#define WARN(message) \
    bEngine::Utils::warn(__FILE__, __LINE__, message);
#define ERROR(message) \
    bEngine::Utils::error(__FILE__, __LINE__, message);

namespace bEngine::Utils {
    void debug(const char* file, int line, const char* message);
    void info(const char* file, int line, const char* message);
    void warn(const char* file, int line, const char* message);
    void error(const char* file, int line, const char* message);

    void log(const char* level, const char* file, int line, const char* message);
}// namespace bEngine::Utils

#endif//GAME_LOGGER_H

#pragma clang diagnostic pop