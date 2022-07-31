#include "sprite.h"

#include <stdio.h>



void setTexture(Sprite* target, const Texture* texture)
{
    target->texture = *texture;
}

void translate(Sprite targetSprite, vec3 targetPos)
{
    glm_vec3_add(targetSprite.position, targetPos, targetSprite.position);
};

Sprite initSprite()
{
    //VBO+VAO
    float verts[] = 
    {
        0.0f, 0.5f,     0.0f, 1.0f,
        0.5f, 0.0f,     1.0f, 0.0f,
        0.0f, 0.0f,     0.0f, 0.0f,

        0.0f, 0.5f,     0.0f, 1.0f,
        0.5f, 0.5f,     1.0f, 1.0f,
        0.5f, 0.0f,     1.0f, 0.0f
    };

    Sprite newSprite;
    newSprite.vbo = createVBO(GL_ARRAY_BUFFER, true);
    newSprite.vao = createVAO();

    bindVAO(newSprite.vao);   

    bufferVBO(newSprite.vbo, verts, 0, 24*sizeof(float));

    enableAttrib(newSprite.vao, newSprite.vbo, 0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0);

    unbindVBO(newSprite.vbo);
    // Unbind VAO buffer
    unbindVAO(newSprite.vao);

    return newSprite;
};