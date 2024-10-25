//
// Created by benajah on 10/25/24.
//

#ifndef GAME_COLOR_H
#define GAME_COLOR_H

#include <string>

namespace bEngine::GFX {
    typedef struct Color_ {
        float red, green, blue, alpha;
    } Color;

    Color color_from_rgb(int red, int green, int blue, int alpha = 255);

    Color color_from_hex(std::string hex_code);
}// namespace bEngine::GFX

#endif//GAME_COLOR_H
