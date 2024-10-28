///
/// \file Application.h
/// \brief Definitions of all logic used for Application
/// \author Benajah Baskin
/// \date 10/15/24
///

#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

// clang-format off
// FUCK YOU CLANG-FORMAT
// DO NOT REORDER THIS
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <filesystem>
#include <variant>

#include "bEngine/Graphics/Color.h"
#include "bEngine/Utils/Math.h"

namespace bEngine::Core {
    // TODO maybe split window properties into another struct i.e Application.Window
    ///
    /// \brief Structure of Application variables
    ///
    struct {
        GLFWwindow *window{};
        float tps = 1.0f / 60.0f;
        float fps{ 0.0f }, fps_limit{ 0.0f };
        bool vsync_state{ false };
    } Application;
    ///
    /// \brief Initializes variables and dependencies for Application to run
    /// \param config_file A filesystem path or string_view of config to load
    ///
    void initializeApplication( const std::variant<std::filesystem::path, std::string_view> &config_file );

    ///
    /// \brief Show window and begin mainloop
    ///
    void startApplication();

    ///
    /// \brief Update all systems and logic
    ///
    void update();

    ///
    /// \brief Render a new framebuffer to the screen
    ///
    void render();

    ///
    /// \brief Sets the background color of Application.window for
    /// \param background_color The new background color
    ///
    void set_window_background_color( GFX::Color background_color );
    ///
    /// \brief Sets the vsync state of Application.window
    /// \param vsync The new vsync state
    ///
    void set_window_vsync( bool vsync );
    ///
    /// \brief Sets the frame rate limit of the Application
    /// \param fps_limit The new Frame Rate limit; fps_limit <= 0 disables frame rate limit
    ///
    void set_fps_limit( int fps_limit );

    ///
    /// \brief Gets width of Application.window
    /// \return The width of Application.window
    ///
    int get_window_width();

    ///
    /// \brief Gets height of Application.window
    /// \return The height of Application.window
    ///
    int get_window_height();

    ///
    /// \brief Asks GLFW for Application.window's dimensions
    /// \return Application.window's dimensions as a Dimension2 struct
    ///
    bEngine::Utils::Math::Dimension2 get_window_size();

    ///
    /// \brief Handles Application logic for window resizing
    /// \param window Application.window
    /// \param width The new width of Application.window
    /// \param height The new height of Application.window
    ///
    static void framebuffer_size_callback( GLFWwindow *window, int width, int height );
}// namespace bEngine::Core

#endif//GAME_APPLICATION_H
