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

#include "resourceloader.h"
#include "include/renderer.h"
#include "include/sprite.h"

#include "game.h"

// Camera
vec3 camPos = {0.0f, 0.0f, 3.0f};
vec3 camFront = {0.0f, 0.0f, -1.0f};
vec3 camUp = {0.0f, 1.0f, 0.0f};
float camSpeed = 1.0f;

float moveX = 0;

int main(void)
{
    initGame();

    // Shader
    Shader shader = createShader("vertexShader.vert", "fragShader.frag");
    //

    SpriteRenderer renderer;
    setShader(&renderer, &shader);

    Sprite sprite = initSprite();
    Sprite sprite2 = initSprite();

    // texture
    Texture textr = loadTextureFromFile("cat.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    useShader(renderer.shader);
    SetUniform1i(renderer.shader, "texture", 0);
    //
    setTexture(&sprite, &textr);


    // transforms
    mat4 view;
    glm_lookat((vec3){0.0f, 0.0f, -1.0f}, (vec3){0.0f, 0.0f, 0.0f}, (vec3){0.0f, 1.0f, 0.0}, view);
    mat4 projection = GLM_MAT4_IDENTITY_INIT;
    glm_ortho(-2.0f, 2.0f, -2.0f, 2.0f, -10.0f, 10.0f, projection);
    // View
    SetUniformMat4(renderer.shader, "view", view[0]);
    // Projection
    SetUniformMat4(renderer.shader, "projection", projection[0]);


    //setPosition(&sprite.transform, (vec3){-2.0, 1.0, 0.0f});

    float x = 0;
    while(!glfwWindowShouldClose(gameWindow))
    {
        updateDeltaTime();
        moveX = 0;

        processInput(gameWindow);

        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        translate(&sprite.transform, (vec3){moveX, 0.0f, 0.0f});
        drawSprite(&renderer, &sprite);
        drawSprite(&renderer, &sprite2);
        
        glfwSwapBuffers(gameWindow);
        glfwPollEvents();
    };

    glfwDestroyWindow(gameWindow);
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

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        moveX = 0.5f*deltaTime;
    };

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        moveX = -0.5f*deltaTime;
    }
};