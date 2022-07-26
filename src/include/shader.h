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
void destroyShader(Shader shader);
void useShader(Shader shader);

#pragma region Uniform Setters
void SetUniformMat4(Shader shader, const char* uniformName, GLfloat* mat);
#pragma endregion

void SetUniformMat4

#endif