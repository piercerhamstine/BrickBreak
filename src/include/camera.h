#ifndef CAMERA_H
#define CAMERA_H

#include "transform.h"

struct Camera
{
    Transform transform;
} typedef Camera;

void initCamera();

#endif