///
/// \file Camera.h
/// \brief Defines logic of the camera view
/// \author Benajah Baskin
/// \date 10/26/24
///
#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include <glm/glm.hpp>

#include "bEngine/Utils/Math.h"

namespace bEngine::GFX {
    ///
    /// \brief Structure of the Camera's data
    ///
    struct {
        glm::mat4 camera_projection{};
        Utils::Math::AABB camera_info{ { 0.0, 0.0 }, { 0, 0 } };
    } Camera;

    ///
    /// \brief Set the Camera's position
    /// \param x The new camera x position
    /// \param y The new camera y position
    ///
    void set_camera_position( double x, double y );
    ///
    /// \brief Set the dimensions of the camera
    /// \param width The new width of the Camera's view
    /// \param height The new height of the Camera's view
    ///
    void set_camera_size( int width, int height );

    ///
    /// \brief Move the cameras position by a distance
    /// \param distance_x The distance to move the Camera's x position
    /// \param distance_y The distance to move the Camera's y position
    ///
    void move_camera( double distance_x, double distance_y );

    ///
    /// \brief Calculate the new projection of the camera
    ///
    void update_camera();
}// namespace bEngine::GFX

#endif//GAME_CAMERA_H
