//
// Created by benajah on 10/15/24.
//
#include "bEngine/Core/Application.h"

#include <cstdlib>
#include <thread>

#include "bEngine/Core/Config.h"
#include "bEngine/Core/Input.h"
#include "bEngine/Graphics/Shader.h"
#include "bEngine/Graphics/VAO.h"
#include "bEngine/Graphics/VBO.h"
#include "bEngine/Utils/Logger.h"


namespace bEngine::Core {
    // TODO May Abstract this function because DAMN
    void initializeApplication(const std::variant<std::filesystem::path, std::string_view> &config_file) {
        try {
            load_config(std::get<std::filesystem::path>(config_file));
        } catch (const std::bad_variant_access &) {
            load_config(std::get<std::string_view>(config_file));
        }


        register_variable<int>("width", 240, "Application");
        register_variable<int>("height", 240, "Application");
        register_variable<std::string>("title", "bEngine", "Application");
        register_variable<int>("tps", 30, "Application");

        if (!glfwInit()) {
            ERROR("GLFW failed to initialize. Terminating now...")
            exit(EXIT_FAILURE);
        }

        Application.window = glfwCreateWindow(get_int("width", "Application"), get_int("height", "Application"),
                                              get_string("title", "Application").c_str(), nullptr, nullptr);

        if (!Application.window) {
            ERROR("Application.window failed to be created. Terminating now...")
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        initialize_input_handler(Application.window);
        glfwSetFramebufferSizeCallback(Application.window, framebuffer_size_callback);

        Application.tps = 1.0f / get_int("tps", "Application");// NOLINT(*-narrowing-conversions)

        DEBUG("Window was created successfully")
        std::string window_info = "\nWindow{\n";
        window_info += "\twidth: " + std::to_string(get_int("width", "Application")) + ",\n";
        window_info += "\theight: " + std::to_string(get_int("height", "Application")) + ",\n";
        window_info += "\ttitle: \"" + get_string("title", "Application") + "\",\n";
        window_info += "\ttps: \"" + std::to_string(get_int("tps", "Application")) + "\",\n";
        window_info += "}";

        INFO(window_info.c_str())

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        

        glfwMakeContextCurrent(Application.window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            ERROR("Failed to initialize GLAD")
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwHideWindow(Application.window);
    }

    void startApplication() {
        glfwShowWindow(Application.window);
        glfwSwapInterval(0);
        DEBUG("Application is starting...")

        glViewport(0, 0, get_window_width(), get_window_height());
        set_background_color(GFX::color_from_hex("#87CEEB"));

        // TESTING CODE BEGIN

        bEngine::GFX::VAO vao;
        float vertices[] = {
                -0.5f, -0.5f, 1.0f, 0.5f, 0.2f,
                0.5f, -0.5f, 1.0f, 0.5f, 0.2f,
                0.0f, 0.5f, 1.0f, 0.5f, 0.2f};
        vao = bEngine::GFX::create_vertex_array(vertices, sizeof(vertices), 5);
        GFX::define_vao_attribute(vao, 0, 0, 2);// vertex position
        GFX::define_vao_attribute(vao, 1, 2, 3);// Color information


        bEngine::GFX::Shader vertex_shader = bEngine::GFX::shader_from_file("/home/benajah/CLionProjects/Game/test.vert");
        bEngine::GFX::Shader frag_shader = bEngine::GFX::shader_from_file("/home/benajah/CLionProjects/Game/test.frag");

        bEngine::GFX::ShaderProgram shader_program = bEngine::GFX::create_shader_program(vertex_shader, frag_shader);

        bEngine::GFX::delete_shader(vertex_shader);
        bEngine::GFX::delete_shader(frag_shader);

        //TESTING CODE END

        double accumulator = 0.0f;
        double last_time = glfwGetTime();
        double current_time;
        double delta_time;
        while (!glfwWindowShouldClose(Application.window)) {
            current_time = glfwGetTime();
            delta_time = current_time - last_time;
            last_time = current_time;
            accumulator += delta_time;

            while (accumulator >= Application.tps) {
                update();

                accumulator -= Application.tps;
            }
            Application.fps = 1.0f / delta_time;// NOLINT(*-narrowing-conversions)

            render();

            //TESTING CODE BEGIN

            GFX::use_shader_program(shader_program);
            GFX::bind_vao(vao);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            // TESTING CODE END

            glfwSwapBuffers(Application.window);

            update_input_data();

            glfwPollEvents();

            /* TODO IMPLEMENT FPS LIMITING
            double sleep_time = Application.target_fps - ( glfwGetTime() - current_time);
            if(sleep_time > 0)
                std::this_thread::sleep_for( std::chrono::duration<double>( sleep_time ) );
            */
        }
        DEBUG("Application was closed. Exiting loop...")

        glfwTerminate();
    }

    int get_window_width() {
        return get_window_size().width;
    }

    int get_window_height() {
        return get_window_size().height;
    }

    bEngine::Utils::Math::Dimension2 get_window_size() {
        int width, height;
        glfwGetWindowSize(Application.window, &width, &height);
        return bEngine::Utils::Math::Dimension2{width, height};
    }

    void update() {
        //use Application.tps for speeds
    }

    void render() {
        glClear(GL_COLOR_BUFFER_BIT);
        //render here
    }

    void set_background_color(GFX::Color background_color) {
        glClearColor(background_color.red, background_color.green, background_color.blue, background_color.alpha);
    }

    void framebuffer_size_callback([[maybe_unused]] GLFWwindow *window, int width, int height) {
        glViewport(0, width, 0, height);
    }
}// namespace bEngine::Core