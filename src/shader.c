#include "include/shader.h"

GLint compileShader(const char* path, GLenum shaderType)
{
    FILE* shaderFile = fopen(path, "rb");
    char* fileText;
    long fileLength;

    if(shaderFile == NULL)
    {
        printf("Error loading shader.");
        exit(1);
    };

    fseek(shaderFile, 0, SEEK_END);
    fileLength = ftell(shaderFile);
    assert(fileLength > 0);

    fseek(shaderFile, 0, SEEK_SET);
    fileText = (char*)calloc(fileLength, sizeof(char));
    assert(fileText != NULL);

    fread(fileText, sizeof(char), fileLength, shaderFile);
    fclose(shaderFile);

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, fileText, NULL);
    glCompileShader(shader);

    GLint success;
    char log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, log);
        printf("Error: Shader compilation failed. ");
        printf(log);
    };

    free(fileText);
    return shader;
};

Shader createShader(const char* vertexPath, const char* fragPath)
{
    Shader newShader;
    newShader.vertexID = compileShader(vertexPath, GL_VERTEX_SHADER);
    newShader.fragmentID = compileShader(fragPath, GL_FRAGMENT_SHADER);

    newShader.program = glCreateProgram();
    glAttachShader(newShader.program, newShader.vertexID);
    glAttachShader(newShader.program, newShader.fragmentID);
    glLinkProgram(newShader.program);

    int success;
    glGetProgramiv(newShader.program, GL_LINK_STATUS, &success);

    return newShader;
};