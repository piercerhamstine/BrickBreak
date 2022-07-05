#ifndef SHADER_H
#define SHADER_H
#include <stdio.h>
#include "glad/gl.h"
#include <GLFW/glfw3.h>

struct Shader
{
    GLuint vertexID;
    GLuint fragmentID;
    GLuint program;

} typedef Shader;

Shader createShader(const char* vertexPath, const char* fragPath);
void destroyShader();
void useShader();

#endif