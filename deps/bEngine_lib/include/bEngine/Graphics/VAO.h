//
// Created by benajah on 10/25/24.
//

#ifndef GAME_VAO_H
#define GAME_VAO_H

#include <glad/glad.h>

#include "VBO.h"

namespace bEngine::GFX {
    typedef struct VAO_ {
        GLuint identifier;
        VBO vbo;
        int stride;
    } VAO;

    VAO create_vertex_array(const float* vertices, long size, int stride);

    void define_vao_attribute(VAO vao, int attribute_number, int location, int distance);

    void bind_vao(VAO vao);
}// namespace bEngine::GFX

#endif//GAME_VAO_H
