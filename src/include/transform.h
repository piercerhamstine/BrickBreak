#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "cglm/cglm.h"

struct Transform
{
    vec3 position;
    vec3 rotation;
    vec3 scale;
} typedef Transform;


Transform initTransform();
void setPosition(Transform* targetTransform, vec3 targetPos);
void translate(Transform* targetTransform, vec3 targetPos);
void scale(Transform* targetTransform, vec3 targetScale);

#endif