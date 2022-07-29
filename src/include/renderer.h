#ifndef RENDERER_H
#define RENDERER_H

#include "sprite.h"

struct SpriteRenderer
{
    Shader shader;
} typedef SpriteRenderer;

void setShader(SpriteRenderer* target, const Shader* shader);

void drawSprite(SpriteRenderer* renderer, Sprite* sprite);

#endif