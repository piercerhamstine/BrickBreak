#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "glad/gl.h"
#include <GLFW/glfw3.h>

#include "include/stb/stb_image.h"
#include "include/shader.h"
#include "include/vbo.h"
#include "include/vao.h"
#include "include/texture.h"

#include "include/renderer.h"
#include "include/sprite.h"

void error_callback(int error, const char* desc);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
    {
        printf("Init failed.");
        exit(EXIT_FAILURE);
        return -1;
    };

    window = glfwCreateWindow(800, 600, "Brick", NULL, NULL);
    if(window == NULL)
    {
        printf("Failed window.");
        glfwTerminate();
        exit(EXIT_FAILURE);
        return -1;
    };
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGL(glfwGetProcAddress))
    {
        printf("GLAD Failure.");
        return -1;
    };

    // Shader
    Shader shader = createShader("vertexShader.vert", "fragShader.frag");
    //
    
    //VBO+VAO
    float verts[]=
    {
        //Pos               // Colors           // Texture Cords
        0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
       -0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
    };

    unsigned int indices[]=
    {
        0,1,3,
        1,2,3
    };

    VBO vbo = createVBO(GL_ARRAY_BUFFER, true);
    VBO ebo = createVBO(GL_ELEMENT_ARRAY_BUFFER, true);

    VAO vao = createVAO();

    bindVAO(vao);   

    bufferVBO(vbo, verts, 0, 32*sizeof(float));
    bufferVBO(ebo, indices, 0, 6*sizeof(unsigned int));

    enableAttrib(vao, vbo, 0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);

    enableAttrib(vao, vbo, 1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));

    enableAttrib(vao, vbo, 2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));

    unbindVBO(vbo);
    // Unbind VAO buffer
    unbindVAO(vao);

    // texture
    Texture textr = createTexture();
    bindTexture(textr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    loadTexture("cat.jpg");
    useShader(shader);
    glUniform1i(glGetUniformLocation(shader.program, "texture"), 0);
    
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        useShader(shader);
        bindVAO(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    };

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
};

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, 1);
    };
};

void error_callback(int error, const char* desc)
{
    fprintf(stderr, "Error: %s\n", desc);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width,height);
};