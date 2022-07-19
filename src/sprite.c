#include "sprite.h"

void setShader(Sprite target, Shader shader)
{
    target.shader = shader;
}

void initSprite(Sprite sprite)
{
    float verts[] = 
    {
        0.0f, 1.0f,     0.0f, 1.0f,
        1.0f, 0.0f,     1.0f, 0.0f,
        0.0f, 0.0f,     0.0f, 0.0f,

        0.0f, 1.0f,     0.0f, 1.0f,
        1.0f, 1.0f,     1.0f, 1.0f,
        1.0f, 0.0f,     1.0f, 0.0f
    };

    sprite.vao = createVAO();
    sprite.vbo = createVBO(GL_ARRAY_BUFFER, 1);

    bindVBO(sprite.vbo);
    bufferVBO(sprite.vbo, verts, 4*sizeof(float), (void*)0);

    bindVAO(sprite.vao);
    enableAttrib(sprite.vao, sprite.vbo, 0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0);

    unbindVAO();
    unbindVBO(sprite.vbo);
};