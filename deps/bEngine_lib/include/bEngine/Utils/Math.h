///
/// \file Math.h
/// \brief Defines Mathematical operations and Data structures
/// \author Benajah Baskin
/// \date 10/25/24
///

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef GAME_MATH_H
#define GAME_MATH_H

namespace bEngine::Utils::Math {

    ///
    /// \brief A 2d Vector {x,y}
    ///
    typedef struct Vector2_ {
        double x, y;
    } Vector2;

    ///
    /// \brief A 2d Dimension {width, height}
    ///
    typedef struct Dimension2_ {
        int width, height;
    } Dimension2;

    ///
    /// \brief An Aligned Axis Bounding Box {position, size}
    ///
    typedef struct AABB_ {
        Vector2 position;
        Dimension2 size;
    } AABB;

    ///
    /// \brief Random variable to check if srand was called or not
    ///
    extern bool srand_initialized;
    ///
    /// \brief Calculate a random int with in a range
    /// \param min The minimum int in the range
    /// \param max The maximum int in the rance
    /// \return A random value within the range min-max
    ///
    int randomValue(int min, int max);
}// namespace bEngine::Utils::Math

#endif//GAME_MATH_H

#pragma clang diagnostic pop