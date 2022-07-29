#include "include/renderer.h"

void setShader(SpriteRenderer* target, const Shader* shader)
{
    target->shader = *shader;
};

void drawSprite(SpriteRenderer* renderer, Sprite* sprite)
{
    useShader(renderer->shader);
    bindVAO(sprite->vao);
    bindTexture(sprite->texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    unbindVAO(sprite->vao);
};