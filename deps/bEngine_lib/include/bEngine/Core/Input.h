///
/// \file Input.h
/// \brief Definitions of all Input variables and handling
/// \author Benajah Baskin
/// \date 10/25/24
///
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#ifndef GAME_INPUT_H
#define GAME_INPUT_H

// INPUT VARIABLES
#define KEY_UNKNOWN (-1)
#define KEY_SPACE 32
#define KEY_APOSTROPHE 39
#define KEY_COMMA 44
#define KEY_MINUS 45
#define KEY_PERIOD 46
#define KEY_SLASH 47
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_SEMICOLON 59
#define KEY_EQUAL 61
#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90
#define KEY_LEFT_BRACKET 91
#define KEY_BACKSLASH 92
#define KEY_RIGHT_BRACKET 93
#define KEY_GRAVE_ACCENT 96
#define KEY_WORLD_1 161
#define KEY_WORLD_2 162
#define KEY_ESCAPE 256
#define KEY_ENTER 257
#define KEY_TAB 258
#define KEY_BACKSPACE 259
#define KEY_INSERT 260
#define KEY_DELETE 261
#define KEY_RIGHT 262
#define KEY_LEFT 263
#define KEY_DOWN 264
#define KEY_UP 265
#define KEY_PAGE_UP 266
#define KEY_PAGE_DOWN 267
#define KEY_HOME 268
#define KEY_END 269
#define KEY_CAPS_LOCK 280
#define KEY_SCROLL_LOCK 281
#define KEY_NUM_LOCK 282
#define KEY_PRINT_SCREEN 283
#define KEY_PAUSE 284
#define KEY_F1 290
#define KEY_F2 291
#define KEY_F3 292
#define KEY_F4 293
#define KEY_F5 294
#define KEY_F6 295
#define KEY_F7 296
#define KEY_F8 297
#define KEY_F9 298
#define KEY_F10 299
#define KEY_F11 300
#define KEY_F12 301
#define KEY_F13 302
#define KEY_F14 303
#define KEY_F15 304
#define KEY_F16 305
#define KEY_F17 306
#define KEY_F18 307
#define KEY_F19 308
#define KEY_F20 309
#define KEY_F21 310
#define KEY_F22 311
#define KEY_F23 312
#define KEY_F24 313
#define KEY_F25 314
#define KEY_KP_0 320
#define KEY_KP_1 321
#define KEY_KP_2 322
#define KEY_KP_3 323
#define KEY_KP_4 324
#define KEY_KP_5 325
#define KEY_KP_6 326
#define KEY_KP_7 327
#define KEY_KP_8 328
#define KEY_KP_9 329
#define KEY_KP_DECIMAL 330
#define KEY_KP_DIVIDE 331
#define KEY_KP_MULTIPLY 332
#define KEY_KP_SUBTRACT 333
#define KEY_KP_ADD 334
#define KEY_KP_ENTER 335
#define KEY_KP_EQUAL 336
#define KEY_LEFT_SHIFT 340
#define KEY_LEFT_CONTROL 341
#define KEY_LEFT_ALT 342
#define KEY_LEFT_SUPER 343
#define KEY_RIGHT_SHIFT 344
#define KEY_RIGHT_CONTROL 345
#define KEY_RIGHT_ALT 346
#define KEY_RIGHT_SUPER 347
#define KEY_MENU 348
#define KEY_LAST KEY_MENU

#define MOUSE_1 0
#define MOUSE_2 1
#define MOUSE_3 2
#define MOUSE_4 3
#define MOUSE_5 4
#define MOUSE_6 5
#define MOUSE_7 6
#define MOUSE_8 7
#define MOUSE_LEFT MOUSE_1
#define MOUSE_RIGHT MOUSE_2
#define MOUSE_MIDDLE MOUSE_3

#include <GLFW/glfw3.h>

#include <unordered_map>

#include "bEngine/Utils/Math.h"

namespace bEngine::Core {
    ///
    /// \brief Structure of all input states and mouse location
    ///
    struct {
        std::unordered_map<int, int> changed_key_states;
        std::unordered_map<int, int> changed_button_states;

        double mouse_x{}, mouse_y{};
    } InputData;

    ///
    /// \brief Initialize Input handling pipeline
    /// \param window Application.window
    ///
    void initialize_input_handler(GLFWwindow* window);

    ///
    /// \brief Clear all input states before polling
    ///
    void update_input_data();

    ///
    /// \brief Check if key is currently in the pressed state
    /// \param key The value of the key
    /// \return Whether or not the key's state is pressed
    ///
    bool is_key_pressed(int key);

    ///
    /// \brief Check if key was just pressed within the last frame
    /// \param key The value of the key
    /// \return Whether or not the key was just pressed within the last frame
    ///
    bool was_key_pressed(int key);

    ///
    /// \brief Check if key was just released within the last frame
    /// \param key The value of the key
    /// \return Whether or not the key was just released within the last frame
    ///
    bool was_key_released(int key);

    ///
    /// \brief Check if mouse button is currently in the pressed state
    /// \param button The value of the mouse button
    /// \return Whether or not the mouse button's state is pressed
    ///
    bool is_mouse_pressed(int button);

    ///
    /// \brief Check if mouse button was just pressed within the last frame
    /// \param button The value of the mouse button
    /// \return Whether or not the mouse button was just pressed within the last frame
    ///
    bool was_mouse_pressed(int button);

    ///
    /// \brief Check if mouse button was just released within the last frame
    /// \param button The value of the mouse button
    /// \return Whether or not the mouse button was just released within the last frame
    ///
    bool was_mouse_released(int button);

    ///
    /// \brief Get mouse's current x position
    /// \return Mouse's current x position
    ///
    double get_mouse_x();

    ///
    /// \brief Get mouse's current y position
    /// \return Mouse's current y position
    ///
    double get_mouse_y();

    ///
    /// \brief Get mouse's current position
    /// \return Mouse's current position as a Vector2{x,y}
    ///
    bEngine::Utils::Math::Vector2 get_mouse_position();

    ///
    /// \brief Update key states when they change
    /// \param window Application.window
    /// \param key The value of the key
    /// \param scancode UNUSED
    /// \param action The new key state
    /// \param mods UNUSED
    ///
    static void key_callback(GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods);

    ///
    /// \brief Update mouse position data when, well when, the mouse moves
    /// \param window Application.window
    /// \param x_position The new mouse x position
    /// \param y_position The new mouse y position
    ///
    // TODO maybe remove this system and just dynamically access the mouse postion
    static void cursor_position_callback([[maybe_unused]] GLFWwindow* window, double x_position, double y_position);

    ///
    /// \brief Update mouse button states when they change
    /// \param window Application.window
    /// \param button The value of the mouse button
    /// \param action The new mouse button state
    /// \param mods UNUSED
    ///
    static void mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods);
}// namespace bEngine::Core

#endif//GAME_INPUT_H

#pragma clang diagnostic pop