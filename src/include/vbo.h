#ifndef VBO_H
#define VBO_H

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>

struct VBO
{
    GLuint buffer;
    GLint bufferType;
    bool isStatic;
} typedef VBO;

VBO createVBO(GLint bufferType, bool isStatic);
void destroyVBO(VBO target);
void bindVBO(VBO target);
void unbindVBO(VBO target);
void bufferVBO(VBO target, void* data, size_t offset, size_t count);

#endif