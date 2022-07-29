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

    // matrices stuff
    mat4 model = GLM_MAT4_IDENTITY_INIT;
    glm_translate(model, sprite->position);
    SetUniformMat4(renderer->shader, "model", model[0]);
    //

    glDrawArrays(GL_TRIANGLES, 0, 6);
    unbindVAO(sprite->vao);
};