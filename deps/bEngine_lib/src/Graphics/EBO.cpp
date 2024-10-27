//
// Created by benajah on 10/26/24.
//

#include "bEngine/Graphics/EBO.h"

namespace bEngine::GFX {
    EBO create_element_buffer(const unsigned int *indicies, long size) {
        EBO ebo;

        glGenBuffers(1, &ebo);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);

        return ebo;
    }
}// namespace bEngine::GFX