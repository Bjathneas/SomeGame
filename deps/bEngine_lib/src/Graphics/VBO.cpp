//
// Created by benajah on 10/25/24.
//
#include "bEngine/Graphics/VBO.h"

namespace bEngine::GFX {
    VBO create_vertex_buffer(const float *vertices, long size) {
        VBO vbo{};

        glGenBuffers(1, &vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

        return vbo;
    }
}// namespace bEngine::GFX