#include "vbo.h"

VBO createVBO(GLint bufferType, bool isStatic)
{
    VBO target;
    target.bufferType = bufferType;
    target.isStatic = isStatic;

    glGenBuffers(1, target.buffer);

    return target;
};

void destroyVBO(VBO target)
{
    glDeleteBuffers(1, &target.buffer);
};

void bindVBO(VBO target)
{
    glBindBuffer(target.bufferType, target.buffer);
};

void bufferVBO(VBO target, void* data, size_t count)
{
    bindVBO(target);
    glBufferData(target.bufferType, count, data, target.isStatic ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
};
