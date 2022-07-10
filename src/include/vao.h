#ifndef VAO_H
#define VAO_H

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "vbo.h"

struct VAO
{
    GLuint attribHandle;
} typedef VAO;

VAO createVAO();
void bindVAO(VAO target);
void destroyVAO();
void enableAttrib(VAO target, VBO buffer, GLuint attribNdx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset);

#endif