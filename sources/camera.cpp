/*
 * File   : camera
 * Author : KsGin 
 * Date   : 2018/9/5
 */

#include "../headers/camera.h"

Camera::Camera() {
    this->position = Math::Vector3();
    this->target = Math::Vector3();
}

Camera::Camera(Math::Vector3 &position, Math::Vector3 &target) {
    this->position = position;
    this->target = target;
}

Camera::Camera(Camera const &camera) {
    this->position = camera.position;
    this->target = camera.target;
}

Camera& Camera::operator=(Camera const &camera) = default;
