//
// Created by benajah on 10/26/24.
//
#include "bEngine/Graphics/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace bEngine::GFX {
    void set_camera_position(double x, double y) {
        Camera.camera_info.position = Utils::Math::Vector2{x, y};

        update_camera();
    }
    void set_camera_size(int width, int height) {
        Camera.camera_info.size = Utils::Math::Dimension2{width, height};

        update_camera();
    }
    void move_camera(double distance_x, double distance_y) {
        Utils::Math::Vector2 camera_position = Camera.camera_info.position;
        Camera.camera_info.position = Utils::Math::Vector2{camera_position.x + distance_x,
                                                           camera_position.y + distance_y};

        update_camera();
    }

    void update_camera() {
        Utils::Math::Vector2 camera_position = Camera.camera_info.position;
        Utils::Math::Dimension2 camera_size = Camera.camera_info.size;

        Camera.camera_projection = glm::ortho(camera_position.x, camera_position.x + camera_size.width,
                                              camera_position.y + camera_size.height, camera_position.y);
    }
}// namespace bEngine::GFX