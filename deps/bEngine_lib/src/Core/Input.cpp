//
// Created by benajah on 10/25/24.
//
#include "bEngine/Core/Input.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace bEngine::Core {
    void initialize_input_handler( GLFWwindow *window ) {
        // Hooking up callbacks, because apparently, users want their shit to work.
        glfwSetKeyCallback( window, key_callback );
        glfwSetCursorPosCallback( window, cursor_position_callback );
        glfwSetMouseButtonCallback( window, mouse_button_callback );
    }

    void update_input_data() {
        // Clean your room -Jordan Peterson
        InputData.changed_button_states.clear();
        InputData.changed_key_states.clear();
    }

    bool is_key_pressed( int key ) {
        return glfwGetKey( glfwGetCurrentContext(), key ) == GLFW_PRESS;
    }

    bool was_key_pressed( int key ) {
        if ( InputData.changed_key_states.find( key ) == InputData.changed_key_states.end() )
            return false;
        return InputData.changed_key_states[ key ] == GLFW_PRESS;
    }

    bool was_key_released( int key ) {
        if ( InputData.changed_key_states.find( key ) == InputData.changed_key_states.end() )
            return false;
        return InputData.changed_key_states[ key ] == GLFW_RELEASE;
    }

    bool is_mouse_pressed( int button ) {
        return glfwGetMouseButton( glfwGetCurrentContext(), button ) == GLFW_PRESS;
    }

    bool was_mouse_pressed( int button ) {
        if ( InputData.changed_button_states.find( button ) == InputData.changed_button_states.end() )
            return false;
        return InputData.changed_button_states[ button ] == GLFW_PRESS;
    }

    bool was_mouse_released( int button ) {
        if ( InputData.changed_button_states.find( button ) == InputData.changed_button_states.end() )
            return false;
        return InputData.changed_button_states[ button ] == GLFW_RELEASE;
    }

    double get_mouse_x() {
        return InputData.mouse_x;
    }

    double get_mouse_y() {
        return InputData.mouse_y;
    }

    Utils::Math::Vector2 get_mouse_position() {
        return bEngine::Utils::Math::Vector2{ get_mouse_x(), get_mouse_y() };
    }

    void key_callback( [[maybe_unused]] GLFWwindow *window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods ) {
        InputData.changed_key_states[ key ] = action;
    }

    void cursor_position_callback( [[maybe_unused]] GLFWwindow *window, double x_position, double y_position ) {
        InputData.mouse_x = x_position;
        InputData.mouse_y = y_position;
    }

    void mouse_button_callback( [[maybe_unused]] GLFWwindow *window, int button, int action, [[maybe_unused]] int mods ) {
        InputData.changed_button_states[ button ] = action;
    }
}// namespace bEngine::Core

#pragma clang diagnostic pop