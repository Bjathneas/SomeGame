//
// Created by benajah on 10/25/24.
//

#ifndef GAME_VBO_H
#define GAME_VBO_H

#include <glad/glad.h>

namespace bEngine::GFX {
    typedef GLuint VBO;

    VBO create_vertex_buffer(const float* vertices, long size);
}// namespace bEngine::GFX
#endif//GAME_VBO_H
