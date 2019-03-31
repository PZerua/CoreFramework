/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "texture.h"

#include <iostream>

namespace gfx
{

Texture::Texture() 
    : TextureBase()
{
    glGenTextures(1, &m_textureId);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
}

bool Texture::loadTexture(const char* filename)
{
    std::string str = filename;
    str = str.substr(str.size() - 4, 4);

    if (str != ".png")
    {
        std::cout << "The image is not in .png format" << std::endl;
        return false;
    }
    
    TexInfo* texinfo = loadTEX(filename);
    if (!texinfo)
    {
        std::cout << "Error reading texture: " << filename << std::endl;
        return false;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, texinfo->bpp, texinfo->width, texinfo->height, 0, GL_RGBA8, GL_UNSIGNED_BYTE, texinfo->data);

    m_width = texinfo->width;
    m_height = texinfo->height;

    delete texinfo->data;
    delete texinfo;

    return true;
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

} // namespace gfx