#ifndef TEXTURE_H
#define TEXTURE_H

#include "stb/stb_image.h"
#include "glad/gl.h"
#include <GLFW/glfw3.h>


struct Texture
{
    GLuint id;
} typedef Texture;

void bindTexture(Texture target);
#endif