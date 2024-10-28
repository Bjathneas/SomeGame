///
/// \file Shader.h
/// \brief Handles creation of OpenGL Shaders and Shader Programs
/// \author Benajah Baskin
/// \date 10/25/24
///

#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <glad/glad.h>

#include <filesystem>

namespace bEngine::GFX {
    ///
    /// \brief Shader data structure
    ///
    typedef struct Shader_ {
        enum TYPE { VERTEX,
                    FRAGMENT,
                    GEOMETRY };
        TYPE type;
        GLuint identifier;
    } Shader;

    typedef GLuint ShaderProgram;

    ///
    /// \brief Load and compile shader from a file
    /// \param shader_file_path The path to the shader file {.vert, .frag}
    /// \return The Shader structure {type, identifier}
    ///
    Shader shader_from_file( const std::filesystem::path &shader_file_path );
    ///
    /// \brief Load and compile shader from a string
    /// \param string The shader source code
    /// \param type The type of shader being created
    /// \return The Shader structure {type, identifier}
    ///
    Shader shader_from_string( const char *string, Shader::TYPE type );

    ///
    /// \brief Delete a shader from memory
    /// \param shader The Shader to delete
    ///
    void delete_shader( Shader shader );

    ///
    /// \brief Create and Compile a Shader Program from a vertex and fragment shader
    /// \param shader_1 Vertex or Fragment shader
    /// \param shader_2 Vertex or Fragment shader
    /// \return The Shader Program
    ///
    ShaderProgram create_shader_program( Shader &shader_1, Shader &shader_2 );

    ///
    /// \brief Bind/Use Shader Program to use for rendering
    /// \param shader_program The Shader Program to Bind/Use
    ///
    void use_shader_program( ShaderProgram shader_program );
}// namespace bEngine::GFX

#endif//GAME_SHADER_H
