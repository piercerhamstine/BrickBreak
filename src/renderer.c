#include "include/renderer.h"

void drawSprite(Sprite sprite)
{
    useShader(sprite.shader);
    bindVAO(sprite.vao);
    bindTexture(sprite.texture);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    unbindVAO(sprite.vao);
};