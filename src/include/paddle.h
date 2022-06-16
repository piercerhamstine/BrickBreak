#ifndef PADDLE_H
#define PADDLE_H

#include "mathutil.h";
#include "collision.h"

struct Paddle
{
    Collider collider;
    Vec2 position;
    
} typedef Paddle;

void paddleInit();

#endif
