//
// Created by benajah on 10/26/24.
//

#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include <glm/glm.hpp>

#include "bEngine/Utils/Math.h"

namespace bEngine::GFX {
    struct {
        glm::mat4 camera_projection{};
        Utils::Math::AABB camera_info{{0.0, 0.0}, {0, 0}};
    } Camera;

    void set_camera_position(double x, double y);
    void set_camera_size(int width, int height);

    void move_camera(double distance_x, double distance_y);

    void update_camera();
}// namespace bEngine::GFX

#endif//GAME_CAMERA_H
