#ifndef VAO_H
#define VAO_H

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>

struct VAO
{
    GLuint attribHandle;
} typedef VAO;

VAO createVAO();
void bindVAO(VAO target);
void destroyVAO();
void enableAttrib(GLuint attribNdx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset);
#endif