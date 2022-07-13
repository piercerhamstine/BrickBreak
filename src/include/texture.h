#ifndef TEXTURE_H
#define TEXTURE_H

#include "stb/stb_image.h"
#include "glad/gl.h"
#include <GLFW/glfw3.h>


struct Texture
{
    GLuint id;
} typedef Texture;

Texture createTexture();
void bindTexture(Texture target);

// Loads texture from given file.
void loadTexture(const char* path);

#endif