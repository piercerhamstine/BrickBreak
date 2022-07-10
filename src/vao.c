#include "include/vao.h"

VAO createVAO()
{
    VAO newVAO;
    glBindVertexArray(1, &newVAO.attribHandle);

    return newVAO;
};

void bindVAO(VAO target)
{
    glBindVertexArray(target.attribHandle);
};

void destroyVAO()
{

};

void enableAttrib(GLuint attribNdx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* offset)
{

};