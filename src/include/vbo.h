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

VBO createVBO(GLsizei size, GLuint buffer);
void destroyVBO(VBO target);
void bindVBO(VBO target);


#endif