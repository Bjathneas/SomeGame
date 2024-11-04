//
// Created by benajah on 10/25/24.
//

#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H
#include <string_view>
using namespace std::string_view_literals;
static constexpr std::string_view config_file = R"(
    [Application]
    width = 800
    height = 600
    title = "Some Game"
    tps = 60
    fps_limit = false
    )"sv;

#endif//GAME_CONFIG_H
