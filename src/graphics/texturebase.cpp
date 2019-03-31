/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#define STB_IMAGE_IMPLEMENTATION
#include "texturebase.h"

namespace gfx
{

TextureBase::TexInfo* TextureBase::loadTEX(const char *texturePath)
{
    TexInfo* texinfo = new TexInfo;
    texinfo->data = stbi_load(texturePath, &texinfo->width, &texinfo->height, &texinfo->bpp, 0);

    if (texinfo->width <= 0 || texinfo->height <= 0 || texinfo->data == NULL)
    {
        delete texinfo;
        return NULL;
    }

    return texinfo;
}

} // namespace gfx
