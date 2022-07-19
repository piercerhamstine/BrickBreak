#include "include/renderer.h"

void drawSprite(Sprite sprite)
{
    useShader(sprite.shader);
    bindTexture(sprite.texture);
    bindVAO(sprite.vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    unbindVAO(sprite.vao);
};