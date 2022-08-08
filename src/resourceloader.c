#include "include/resourceloader.h"

Texture loadTextureFromFile(const char* texturePath, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filter)
{
    Texture newTextr;

    int width, height, nrChannels;

    stbi_set_flip_vertically_on_load(1);

    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

    generateglTexture(&newTextr, width, height, data, wrap_s, wrap_t, min_filter, mag_filter);

    stbi_image_free(data);
};

static void generateglTexture(Texture* targetTextr, GLuint width, GLuint height, unsigned char* data, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filter)
{
    glGenTextures(1, &targetTextr->id);
    glBindTexture(GL_TEXTURE_2D, targetTextr->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
    }
};