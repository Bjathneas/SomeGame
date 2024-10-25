//
// Created by benajah on 10/15/24.
//

#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

// clang-format off
// FUCK YOU CLANG-FORMAT
// DO NOT REORDER THIS
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <filesystem>

#include "bEngine/Graphics/Color.h"
#include "bEngine/Utils/Math.h"

namespace bEngine::Core {
    struct {
        GLFWwindow *window{};
        float tps = 1.0f / 60.0f;
        float fps{0.0f};
    } Application;

    void initializeApplication(const std::filesystem::path &config_file_path);

    void startApplication();

    void update();

    void render();

    void set_background_color(GFX::Color background_color);

    int get_window_width();

    int get_window_height();

    bEngine::Utils::Math::Dimension2 get_window_size();

    static void framebuffer_size_callback([[maybe_unused]] GLFWwindow *window, int width, int height);
}// namespace bEngine::Core

#endif//GAME_APPLICATION_H
