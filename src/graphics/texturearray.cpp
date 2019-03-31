/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "texturearray.h"

#include <iostream>

namespace gfx
{

TextureArray::TextureArray(GLuint width, GLuint height)
    : TextureBase(width, height),
    m_textureCount(0)
{
    glGenTextures(1, &m_textureId);
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureId);

    glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, (GLint*)&m_maxLayers);

    glTexStorage3D(GL_TEXTURE_2D_ARRAY,
        1,                      // Mipmaps
        GL_RGBA8,               // Internal format
        m_width, m_height,      // Width, Height
        m_maxLayers             // Number of layers
    );
}

GLuint TextureArray::getTexture(const char *texturePath)
{
    // Get id from the map if the texture is already uploaded
    if (m_textures.count(texturePath))
        return m_textures[texturePath];
    else
    {
        // Upload the texture, add it to the map and get the current id
        if(addTexture(texturePath))
            return m_textureCount - 1;
        else return -1;
    }
}

bool TextureArray::addTexture(const char *texturePath)
{
    if (m_textureCount >= m_maxLayers)
    {
        std::cout << "You can't submit more textures to this texture array" << std::endl;
        return false;
    }

    std::string str = texturePath;
    str = str.substr(str.size() - 4, 4);

    if (str != ".png")
    {
        std::cout << "The image is not in .png format" << std::endl;
        return false;
    }

    TexInfo* texinfo = loadTEX(texturePath);
    if (!texinfo)
    {
        std::cout << "Error reading texture: " << texturePath << std::endl;
        return false;
    }

    if (texinfo->width != m_width || texinfo->height != m_height)
    {
        std::cout << "The texture submited to the texture array doesn't have a valid size" << std::endl;
        return false;
    }

    // Add to the map <textureName, index>
    m_textures[texturePath] = m_textureCount;

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexSubImage3D(GL_TEXTURE_2D_ARRAY,
        0,                                        // Mipmap number
        0, 0, m_textureCount++,                   // Xoffset, Yoffset, Zoffset
        texinfo->width, texinfo->height, 1,       // Width, Height, Depth
        GL_RGBA,                                  // Format
        GL_UNSIGNED_BYTE,                         // Type
        texinfo->data);                           // Pointer to data

    m_width = texinfo->width;
    m_height = texinfo->height;

    delete texinfo->data;
    delete texinfo;

    return true;
}

void TextureArray::bind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureId);
}

void TextureArray::unbind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

} // namespace gfx
