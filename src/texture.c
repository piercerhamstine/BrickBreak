#include "include/texture.h"

Texture createTexture()
{
    Texture newTexture;

    glGenTextures(1, &newTexture.id);

    return newTexture;
};

// Bind the provided Texture, all OpenGL Texture operations will apply to the currently bound texture.
void bindTexture(Texture target)
{
    glBindTexture(GL_TEXTURE_2D, target.id);
};

void unbindTexture()
{
};

void loadTexture(const char* path)
{
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(1);

    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
    }

    stbi_image_free(data);
};