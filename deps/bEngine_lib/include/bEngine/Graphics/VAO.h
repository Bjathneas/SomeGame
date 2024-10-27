//
// Created by benajah on 10/25/24.
//

#ifndef GAME_VAO_H
#define GAME_VAO_H

#include <glad/glad.h>

#include "EBO.h"
#include "VBO.h"

namespace bEngine::GFX {
    typedef struct VAO_ {
        GLuint identifier;
        VBO vbo;
        EBO ebo;
        int stride;
    } VAO;

    VAO create_vertex_array(VBO vbo, int stride);
    VAO create_vertex_array(VBO vbo, EBO ebo, int stride);

    void define_vao_attribute(VAO vao, int attribute_number, int location, int distance);

    void bind_vao(VAO vao);
}// namespace bEngine::GFX

#endif//GAME_VAO_H
