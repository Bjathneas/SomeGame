//
// Created by benajah on 10/26/24.
//

#ifndef GAME_EBO_H
#define GAME_EBO_H

#include <glad/glad.h>

namespace bEngine::GFX {
    typedef GLuint EBO;

    EBO create_element_buffer(const unsigned int* indicies, long size);
}// namespace bEngine::GFX

#endif//GAME_EBO_H
