#include <vector>

#include "mge/core/rendering/TextureArray.hpp"
#include "mge/core/rendering/Texture.hpp"
#include "mge/config.hpp"

TextureArray::TextureArray() : _id() {
	glGenTextures(1, &_id);
}

TextureArray::~TextureArray()
{
	glDeleteTextures(1, &_id);
}

GLuint TextureArray::getId() {
	return _id;
}