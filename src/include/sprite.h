#ifndef SPRITE_H
#define SPRITE_H

#include "cglm/cglm.h"
#include "vao.h"
#include "vbo.h"
#include "texture.h"
#include "shader.h"
#include "transform.h"

struct Sprite
{
    Transform transform;
    
    VAO vao;
    VBO vbo;
    Texture texture;
} typedef Sprite;

Sprite initSprite();
void setTexture(Sprite* target, const Texture* texture);
#endif