#ifndef GAME_H
#define GAME_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include "cglm/cglm.h"

#include "renderer.h"
#include "gameobject.h"

GLFWwindow* gameWindow;

int initGame();
void cleanGame();


void error_callback(int error, const char* desc);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
#endif