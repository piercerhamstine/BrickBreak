#include "glad/gl.h"
#include <GLFW/glfw3.h>


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/shader.h"

#include "stb_image.h"

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

    unsigned int EBO;
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    // Unbind VBO buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // Unbind VAO buffer
    glBindVertexArray(0);
    //

    // texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("contain.jpg", &width, &height, &nrChannels, 0);

    if(data)
    {
        glTexImage2d(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
    };
    stbi_image_free(data);

    float texCord[] =
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f
    };
    float borderColor[] = {1.0f, 1.0f, 0.0f, 1.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    //

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        useShader(shader);
        glBindVertexArray(VAO);
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