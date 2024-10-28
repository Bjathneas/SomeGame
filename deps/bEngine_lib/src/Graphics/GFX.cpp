//
// Created by benajah on 10/27/24.
//

#include "bEngine/Graphics/GFX.h"

namespace bEngine::GFX {
    EBO create_element_buffer( const unsigned int *indices, long size ) {
        EBO ebo;

        glGenBuffers( 1, &ebo );

        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebo );
        glBufferData( GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW );

        return ebo;
    }

    VBO create_vertex_buffer( const float *vertices, long size ) {
        VBO vbo{};

        glGenBuffers( 1, &vbo );

        glBindBuffer( GL_ARRAY_BUFFER, vbo );

        glBufferData( GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW );

        return vbo;
    }

    VAO create_vertex_array( VBO vbo, int stride ) {
        VAO vao{};

        vao.vbo = vbo;
        vao.ebo = 0;

        glGenVertexArrays( 1, &vao.identifier );

        vao.stride = stride;

        return vao;
    }

    VAO create_vertex_array( VBO vbo, EBO ebo, int stride ) {
        VAO vao{};

        vao.vbo = vbo;
        vao.ebo = ebo;

        glGenVertexArrays( 1, &vao.identifier );

        vao.stride = stride;

        return vao;
    }

    void define_vao_attribute( VAO vao, int attribute_number, int location, int distance ) {
        glBindVertexArray( vao.identifier );
        glBindBuffer( GL_ARRAY_BUFFER, vao.vbo );

        if ( vao.ebo != 0 )
            glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, vao.ebo );

        glVertexAttribPointer( attribute_number, distance, GL_FLOAT, GL_FALSE, vao.stride * sizeof( float ), ( void * ) ( location * sizeof( float ) ) );// NOLINT(*-narrowing-conversions)
        glEnableVertexAttribArray( attribute_number );
        glBindVertexArray( 0 );
    }

    void bind_vao( VAO vao ) {
        glBindVertexArray( vao.identifier );
    }
}// namespace bEngine::GFX