#include "include/texture.h"

// Bind the provided Texture, all OpenGL Texture operations will apply to the currently bound texture.
void bindTexture(Texture target)
{
    glBindTexture(GL_TEXTURE_2D, target.id);
};
