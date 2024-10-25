//
// Created by benajah on 10/25/24.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef GAME_MATH_H
#define GAME_MATH_H

namespace bEngine::Utils::Math {

    typedef struct Vector2_ {
        double x, y;
    } Vector2;

    typedef struct Dimension2_ {
        int width, height;
    } Dimension2;

    typedef struct AABB_ {
        Vector2 position;
        Dimension2 size;
    } AABB;

    extern bool srand_initialized;
    int randomValue(int min, int max);
}// namespace bEngine::Utils::Math

#endif//GAME_MATH_H

#pragma clang diagnostic pop