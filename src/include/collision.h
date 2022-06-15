#ifndef COLLISION_H
#define COLLISION_H

#include "mathutil.h"

struct Collider
{
    Rect colliderSize;
} typedef Collider;

bool aabbcollision(Collider* c1, Collider* c2);

#endif