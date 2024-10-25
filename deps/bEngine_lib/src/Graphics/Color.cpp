#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by benajah on 10/25/24.
//
#include "bEngine/Graphics/Color.h"

#include <cassert>

#include "bEngine/Utils/Logger.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-narrowing"
namespace bEngine::GFX {
    Color color_from_rgb(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) {
        if (red > 255 || green > 255 || blue > 255 || alpha > 255) {
            std::string warning = "RGBA(" + std::to_string(red) + ", " + std::to_string(green) + ", " + std::to_string(blue) + ", " + std::to_string(alpha) + ") values cannot be greater than 255";
            WARN(warning.c_str())

            red = (red > 255) ? 255 : red;
            green = (green > 255) ? 255 : green;
            blue = (blue > 255) ? 255 : blue;
            alpha = (alpha > 255) ? 255 : alpha;
        }

        return bEngine::GFX::Color{red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f};
    }

    Color color_from_hex(std::string hex_code) {
        if (hex_code[0] == '#')
            hex_code.erase(hex_code.begin(), hex_code.begin() + 1);

        assert(!(hex_code.length() > 8) && (hex_code.length() % 2) == 0 && hex_code.length() >= 6);

        unsigned red, green, blue, alpha;

        red = std::stoi(hex_code.substr(0, 2), nullptr, 16);

        green = std::stoi(hex_code.substr(2, 2), nullptr, 16);

        blue = std::stoi(hex_code.substr(4, 2), nullptr, 16);

        alpha = (hex_code.length() == 8) ? std::stoi(hex_code.substr(6, 2), nullptr, 16) : 255;

        return color_from_rgb(red, green, blue, alpha);
    }
}// namespace bEngine::GFX
#pragma clang diagnostic pop
#pragma clang diagnostic pop