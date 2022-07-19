#include "sprite.h"

#include <stdio.h>

void setShader(Sprite target, const Shader shader)
{
    target.shader = shader;
}

void setTexture(Sprite target, const Texture texture)
{
    target.texture = texture;
}

void initSprite(Sprite sprite)
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

    sprite.vbo = createVBO(GL_ARRAY_BUFFER, true);
    sprite.vao = createVAO();

    bindVAO(sprite.vao);   

    bufferVBO(sprite.vbo, verts, 0, 24*sizeof(float));

    enableAttrib(sprite.vao, sprite.vbo, 0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0);

    unbindVBO(sprite.vbo);
    // Unbind VAO buffer
    unbindVAO(sprite.vao);
};