#include "include/vao.h"

VAO createVAO()
{
    VAO newVAO;
    glGenVertexArrays(1, &newVAO.attribHandle);

    return newVAO;
};

void bindVAO(VAO target)
{
    glBindVertexArray(target.attribHandle);
};

void unbindVAO()
{
    glBindVertexArray(0);
};

void destroyVAO()
{

};

void enableAttrib(VAO target, VBO buffer, GLuint attribNdx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset)
{
    bindVAO(target);
    bindVBO(buffer);

    glVertexAttribPointer(attribNdx, size, type, normalized, stride, offset);
    glEnableVertexAttribArray(attribNdx);

    unbindVAO(target);
    unbindVBO(buffer);
};