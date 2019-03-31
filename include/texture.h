/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "texturebase.h"

namespace gfx
{

class Texture : public TextureBase
{

public:
    Texture();
    void bind() const ;
    void unbind() const;
    bool loadTexture(const char* filename);

};

} // namespace gfx