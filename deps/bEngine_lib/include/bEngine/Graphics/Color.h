///
/// \file Color.h
/// \brief Definition of a color
/// \author Benajah Baskin
/// \date 10/25/24
///

#ifndef GAME_COLOR_H
#define GAME_COLOR_H

#include <string>

namespace bEngine::GFX {
    ///
    /// \brief OpenGL values for a color
    ///
    typedef struct Color_ {
        float red, green, blue, alpha;
    } Color;

    ///
    /// \brief Create a Color from RGBA values
    /// \param red The red value 0-255
    /// \param green The green value 0-255
    /// \param blue The blue value 0-255
    /// \param alpha The opacity value 0-255 -> defaults to 255 if not defined
    /// \return The Color according to its RGBA values
    ///
    Color color_from_rgb(int red, int green, int blue, int alpha = 255);

    ///
    /// \brief Create a Color from a HexCode
    /// \param hex_code The HexCode representation of the color
    /// \return The Color according to its hex value
    ///
    Color color_from_hex(std::string hex_code);
}// namespace bEngine::GFX

#endif//GAME_COLOR_H
