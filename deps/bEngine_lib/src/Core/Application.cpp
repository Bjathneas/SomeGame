//
// Created by benajah on 10/15/24.
//
#include "bEngine/Core/Application.h"

#include <imgui.h>

#include <cstdlib>
#include <thread>

#include "bEngine/Core/Config.h"
#include "bEngine/Core/Input.h"
#include "bEngine/Graphics/GFX.h"
#include "bEngine/Graphics/Shader.h"
#include "bEngine/Utils/Logger.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


namespace bEngine::Core {
    void initializeApplication(const std::variant<std::filesystem::path, std::string_view> &config_file) {
        // CONFIG

        try {
            load_config(std::get<std::filesystem::path>(config_file));
        } catch (const std::bad_variant_access &) {
            load_config(std::get<std::string_view>(config_file));
        }

        register_variable<int>("width", 240, "Application");
        register_variable<int>("height", 240, "Application");
        register_variable<std::string>("title", "bEngine", "Application");
        register_variable<int>("tps", 30, "Application");
        register_variable<int>("fps_limit", 60, "Application");

        // GLFW

        if (!glfwInit()) {
            ERROR("GLFW failed to initialize. Terminating now...")
            exit(EXIT_FAILURE);
        }


        // Application
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
        set_fps_limit(get_int("fps_limit", "Application"));    // NOLINT(*-narrowing-conversions)

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

        // GLAD

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            ERROR("Failed to initialize GLAD")
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        // IMGUI
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui_ImplGlfw_InitForOpenGL(Application.window, true);
        ImGui_ImplOpenGL3_Init();

        glfwHideWindow(Application.window);
    }

    void startApplication() {
        glfwShowWindow(Application.window);
        set_window_vsync(false);
        DEBUG("Application is starting...")

        glViewport(0, 0, get_window_width(), get_window_height());
        set_window_background_color(GFX::color_from_hex("#87CEEB"));

        // TESTING CODE BEGIN

        bEngine::GFX::VAO vao;
        float vertices[] = {
                1.0f, 1.0f, 1.0f, 0.5f, 0.2f,  // top-right
                1.0f, -1.0f, 1.0f, 0.5f, 0.2f, // bottom-right
                -1.0f, -1.0f, 1.0f, 0.5f, 0.2f,// bottom-left
                -1.0f, 1.0f, 1.0f, 0.5f, 0.2f, // top-left
        };

        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3};

        vao = bEngine::GFX::create_vertex_array(GFX::create_vertex_buffer(vertices, sizeof(vertices)), GFX::create_element_buffer(indices, sizeof(indices)), 5);
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

            glClear(GL_COLOR_BUFFER_BIT);

            //TESTING CODE BEGIN

            GFX::use_shader_program(shader_program);
            GFX::bind_vao(vao);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            // TESTING CODE END

            render();


            glfwSwapBuffers(Application.window);

            update_input_data();

            glfwPollEvents();

            if (Application.fps_limit > 0.0f) {
                double sleep_time = Application.fps_limit - (glfwGetTime() - current_time);
                if (sleep_time > 0)
                    std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
            }
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
    void set_window_vsync(bool vsync) {
        Application.vsync_state = vsync;
        glfwSwapInterval(vsync);
    }

    void set_fps_limit(int fps_limit) {
        Application.fps_limit = 1.0f / fps_limit;// NOLINT(*-narrowing-conversions)
    }

    void update() {
        //use Application.tps for speeds
    }

    void render() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // TODO Implement Collapsing tabs for each category/struct
        // Create Debugging Window
#ifdef DEBUG_MODE
        ImGui::Begin("Info Window", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("FPS Rate/Limit: %s/%s\nVsync: %s\nTick Speed: %s",
                    std::to_string((int) std::ceil(Application.fps)).c_str(),
                    std::to_string((int) std::ceil(1.0f / Application.fps_limit)).c_str(),
                    Application.vsync_state ? "True" : "False",
                    std::to_string((int) std::ceil(1.0f / Application.tps)).c_str());
        ImGui::End();
#endif


        //render here
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void set_window_background_color(GFX::Color background_color) {
        glClearColor(background_color.red, background_color.green, background_color.blue, background_color.alpha);
    }

    void framebuffer_size_callback([[maybe_unused]] GLFWwindow *window, int width, int height) {
        glViewport(0, width, 0, height);
    }
}// namespace bEngine::Core