///
/// \file Logger.h
/// \brief A Logging system that uses files and line numbers
/// \author Benajah Baskin
/// \date 10/17/24
///

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#ifndef DEBUG_MODE
#define DEBUG( message )
#else
#define DEBUG( message ) \
    bEngine::Utils::debug( __FILE__, __LINE__, message );
#endif//DEBUG_MODE

#define INFO( message ) \
    bEngine::Utils::info( __FILE__, __LINE__, message );
#define WARN( message ) \
    bEngine::Utils::warn( __FILE__, __LINE__, message );
#define ERROR( message ) \
    bEngine::Utils::error( __FILE__, __LINE__, message );

namespace bEngine::Utils {
    ///
    /// \brief Log a message with the level DEBUG
    /// \param file The file that is calling the function
    /// \param line The line that is calling the function
    /// \param message The message to log
    ///
    void debug( const char* file, int line, const char* message );
    ///
    /// \brief Log a message with the level INFO
    /// \param file The file that is calling the function
    /// \param line The line that is calling the function
    /// \param message The message to log
    ///
    void info( const char* file, int line, const char* message );
    ///
    /// \brief Log a message with the level WARN
    /// \param file The file that is calling the function
    /// \param line The line that is calling the function
    /// \param message The message to log
    ///
    void warn( const char* file, int line, const char* message );
    ///
    /// \brief Log a message with the level ERROR
    /// \param file The file that is calling the function
    /// \param line The line that is calling the function
    /// \param message The message to log
    ///
    void error( const char* file, int line, const char* message );

    ///
    /// \brief Log a message according to specified parameters
    /// \param level The log level
    /// \param file The file that is calling the function
    /// \param line The line that is calling the function
    /// \param message The message to log
    ///
    void log( const char* level, const char* file, int line, const char* message );
}// namespace bEngine::Utils

#endif//GAME_LOGGER_H

#pragma clang diagnostic pop