//
// Created by benajah on 10/25/24.
//
#include "bEngine/Graphics/Shader.h"

#include <cassert>
#include <fstream>

#include "bEngine/Utils/Logger.h"

namespace bEngine::GFX {
    Shader shader_from_file(const std::filesystem::path &shader_file_path) {
        std::ifstream file(shader_file_path);
        //convert file into a string
        std::stringstream ss;
        ss << file.rdbuf();

        std::string content = ss.str();

        file.close();
        //check file extension
        std::string file_extension = shader_file_path.extension();

        if (file_extension == ".vert")
            return shader_from_string(content.c_str(), Shader::TYPE::VERTEX);
        else if (file_extension == ".frag")
            return shader_from_string(content.c_str(), Shader::TYPE::FRAGMENT);
        else
            assert(true == false);// TODO remove this god awful solution
    }

    Shader shader_from_string(const char *string, Shader::TYPE type) {
        Shader shader{};

        switch (type) {
            case Shader::TYPE::VERTEX:
                shader.identifier = glCreateShader(GL_VERTEX_SHADER);
                shader.type = Shader::TYPE::VERTEX;
                break;
            case Shader::TYPE::FRAGMENT:
                shader.identifier = glCreateShader(GL_FRAGMENT_SHADER);
                shader.type = Shader::TYPE::FRAGMENT;
                break;
            case Shader_::GEOMETRY:
                break;
        }

        glShaderSource(shader.identifier, 1, &string, nullptr);
        glCompileShader(shader.identifier);

        int shader_compiled;
        glGetShaderiv(shader.identifier, GL_COMPILE_STATUS, &shader_compiled);

        if (!shader_compiled) {
            char what_went_wrong[512];
            glGetShaderInfoLog(shader.identifier, 512, nullptr, what_went_wrong);

            std::string oof = "Shader Failed to Compile, with the Error {";
            oof += what_went_wrong;
            oof += "}";

            WARN(oof.c_str())
            exit(EXIT_FAILURE);
        }

        return shader;
    }
    ShaderProgram create_shader_program(Shader &shader_1, Shader &shader_2) {
        ShaderProgram shader_program{};
        shader_program = glCreateProgram();
        glAttachShader(shader_program, shader_1.identifier);
        glAttachShader(shader_program, shader_2.identifier);
        glLinkProgram(shader_program);

        int program_compiled;
        glGetProgramiv(shader_program, GL_COMPILE_STATUS, &program_compiled);

        if (!program_compiled) {
            char what_went_wrong[512];
            glGetProgramInfoLog(shader_program, 512, nullptr, what_went_wrong);

            std::string oof = "Shader Program Failed to Compile, with the Error {";
            oof += what_went_wrong;
            oof += "}";

            WARN(oof.c_str())
            exit(EXIT_FAILURE);
        }

        return shader_program;
    }
    void delete_shader(Shader shader) {
        glDeleteShader(shader.identifier);
    }

    void use_shader_program(ShaderProgram shader_program) {
        glUseProgram(shader_program);
    }
}// namespace bEngine::GFX