#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include "GLFW/glfw3.h"
#include "texture.h"

#define wrap_s(t)

// For now this will just return the Texture struct. Will implement a map or some other data structure to store loaded resources.
Texture loadTextureFromFile(const char* texturePath, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filter);
void generateglTexture(GLuint width, GLuint height, unsigned char* data);
#endif