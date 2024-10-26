//
// Created by benajah on 10/25/24.
//
#include "bEngine/Graphics/VAO.h"

namespace bEngine::GFX {
    VAO create_vertex_array(const float *vertices, long size, int stride) {
        VAO vao{};

        vao.vbo = create_vertex_buffer(vertices, size);

        glGenVertexArrays(1, &vao.identifier);

        vao.stride = stride;

        return vao;
    }
    void define_vao_attribute(VAO vao, int attribute_number, int location, int distance) {
        glBindVertexArray(vao.identifier);
        glBindBuffer(GL_ARRAY_BUFFER, vao.vbo);

        glVertexAttribPointer(attribute_number, distance, GL_FLOAT, GL_FALSE, vao.stride * sizeof(float), (void *) (location * sizeof(float)));
        glEnableVertexAttribArray(attribute_number);
    }

    void bind_vao(VAO vao) {
        glBindVertexArray(vao.identifier);
    }
}// namespace bEngine::GFX