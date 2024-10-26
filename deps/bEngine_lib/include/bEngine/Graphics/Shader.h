//
// Created by benajah on 10/25/24.
//

#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <glad/glad.h>

#include <filesystem>

namespace bEngine::GFX {
    typedef struct Shader_ {
        enum TYPE { VERTEX,
                    FRAGMENT,
                    GEOMETRY };
        TYPE type;
        GLuint identifier;
    } Shader;

    typedef struct ShaderProgram_ {
        GLuint identifier;
    } ShaderProgram;

    Shader shader_from_file(const std::filesystem::path &shader_file_path);
    Shader shader_from_string(const char *string, Shader::TYPE type);

    void delete_shader(Shader shader);

    ShaderProgram create_shader_program(Shader &shader_1, Shader &shader_2);

    void use_shader_program(ShaderProgram shader_program);
}// namespace bEngine::GFX

#endif//GAME_SHADER_H
