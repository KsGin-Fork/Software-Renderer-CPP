/*
 * File   : camera
 * Author : KsGin 
 * Date   : 2018/9/5
 */

#ifndef SOFTWARE_RENDERER_CPP_CAMERA_H
#define SOFTWARE_RENDERER_CPP_CAMERA_H


#include "../include/vector.hpp"

/**
 * camera class
 */
class Camera {
public:
    /**
     * position
     */
    Math::Vector3 position;
    /**
     * target (look to)
     */
    Math::Vector3 target;

    /**
     * default constructor
     */
    Camera();

    /**
     * value ref copy constructor
     */
    Camera(Math::Vector3 &position, Math::Vector3 &target);

    /**
     * object ref copy constructor
     */
    Camera(Camera const &camera);

    /**
     * override =
     */
    Camera &operator=(Camera const &camera);

};


#endif //SOFTWARE_RENDERER_CPP_CAMERA_H
