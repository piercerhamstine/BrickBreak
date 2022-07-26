#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "glad/gl.h"
#include <GLFW/glfw3.h>

#include "include/cglm/cglm.h"

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

    Sprite sprite = initSprite();
    setShader(&sprite, &shader);

    // Move this into Sprite.h
    // texture
    Texture textr = createTexture();
    bindTexture(textr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    loadTexture("cat.jpg");
    useShader(sprite.shader);
    glUniform1i(glGetUniformLocation(sprite.shader.program, "texture"), 0);
    //

    setTexture(&sprite, &textr);

    // transforms
    mat4 model = GLM_MAT4_IDENTITY_INIT;
    glm_translate(model, (vec3){0.0f, 0.0f, 1.0f});


    mat4 view = GLM_MAT4_IDENTITY_INIT;
    glm_translate(view, (vec3){0.0f, 0.0f, -1.0f});

    mat4 projection = GLM_MAT4_IDENTITY_INIT;
    glm_ortho(-2.0f, 2.0f, -2.0f, 2.0f, -1.0f, 1.0f, projection);

    GLuint modelLoc, viewLoc, projectionLoc;

    // Model
    modelLoc = glGetUniformLocation(sprite.shader.program, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);

    // View
    viewLoc = glGetUniformLocation(sprite.shader.program, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view[0]);

    // Projection
    projectionLoc = glGetUniformLocation(sprite.shader.program, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection[0]);

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawSprite(sprite);

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