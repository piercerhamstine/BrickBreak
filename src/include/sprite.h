#ifndef SPRITE_H
#define SPRITE_H

#include "vao.h"
#include "vbo.h"
#include "texture.h"

struct Sprite
{
    VAO vao;
    VBO vbo;
    Texture texture;
} typedef Sprite;

#endif