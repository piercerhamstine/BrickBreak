#ifndef SPRITE_H
#define SPRITE_H

#include "vao.h"
#include "vbo.h"
#include "texture.h"
#include "shader.h"

struct Sprite
{
    VAO vao;
    VBO vbo;
    Texture texture;
    Shader shader;
} typedef Sprite;

void initSprite(Sprite sprite);
void setShader(Sprite target, const Shader shader);
void setTexture(Sprite target, const Texture texture);
#endif