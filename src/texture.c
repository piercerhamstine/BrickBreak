#include "include/texture.h"

Texture createTexture()
{
    Texture newTexture;

    return newTexture;
};

// Bind the provided Texture, all OpenGL Texture operations will apply to the currently bound texture.
void bindTexture(Texture target)
{
    glBindTexture(GL_TEXTURE_2D, target.id);
};

void unbindTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}