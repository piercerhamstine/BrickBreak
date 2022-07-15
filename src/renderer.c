#include "include/renderer.h"

void drawSprite(Sprite sprite)
{
    useShader(sprite.shader);
    
    bindTexture(sprite.texture);

    bindVAO(sprite.vao);

    // Draw here

    unbindVAO(sprite.vao);
};