#ifndef SPRITE_H
#define SPRITE_H

#include "cglm/cglm.h"
#include "vao.h"
#include "vbo.h"
#include "texture.h"
#include "shader.h"

struct Sprite
{
    // Will probably move this to it's own file.
    vec3 position;
    vec3 rotation;
    vec3 scale;

    VAO vao;
    VBO vbo;
    Texture texture;
} typedef Sprite;

Sprite initSprite();
void setTexture(Sprite* target, const Texture* texture);

#pragma region Transformations
void translate(Sprite targetSprite, vec3 targetPos);
#pragma endregion

#endif