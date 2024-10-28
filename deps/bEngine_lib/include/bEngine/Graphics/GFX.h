///
/// \file GFX.h
/// \brief Handles creation of OpenGL objects
/// \author Benajah Baskin
/// \date 10/27/24
///

#ifndef GAME_GFX_H
#define GAME_GFX_H

#include <glad/glad.h>

namespace bEngine::GFX {
    typedef GLuint VBO;
    typedef GLuint EBO;
    typedef struct VAO_ {
        GLuint identifier;
        VBO vbo;
        EBO ebo;
        int stride;
    } VAO;

    ///
    /// \brief Creates Element Buffer Object
    /// \param indices Indices array in the drawing order
    /// \param size Size of the array
    /// \return Element Buffer Object ID number
    ///
    EBO create_element_buffer( const unsigned int* indices, long size );

    ///
    /// \brief Creates Vertex Buffer Object
    /// \param vertices Vertex data array
    /// \param size Size of the array
    /// \return Vertex Buffer Object ID number
    ///
    VBO create_vertex_buffer( const float* vertices, long size );

    ///
    /// \brief Creates Vertex Array Object
    /// \param vbo The Vertex Buffer Object ID number to bind to VAO
    /// \param stride The size of each row of data
    /// \return Vertex Array Object structure {id, vbo, stride}
    ///
    VAO create_vertex_array( VBO vbo, int stride );
    ///
    /// \brief Creates Vertex Array Object
    /// \param vbo The Vertex Buffer Object ID number to bind to VAO
    /// \param ebo The Element Buffer Object ID number to bind to VAO
    /// \param stride The size of each row of data
    /// \return Vertex Array Object structure {id, vbo, ebo, stride}
    ///
    VAO create_vertex_array( VBO vbo, EBO ebo, int stride );

    ///
    /// \brief Define a column in vertex data
    /// \param vao Vertex Array Object to define attribute for
    /// \param attribute_number The number to assign to the column -> in glsl (location = attribute_number)
    /// \param location Where in the vertex data to start reading from
    /// \param distance How far from the location does the vertex data extend
    ///
    void define_vao_attribute( VAO vao, int attribute_number, int location, int distance );

    ///
    /// \brief Bind Vertex Array Object
    /// \param vao The Vertex Array Object to bind
    ///
    void bind_vao( VAO vao );
}// namespace bEngine::GFX

#endif//GAME_GFX_H
