#include <iostream>
#include <string>

#include "mge/core/rendering/Texture.hpp"
#include "mge/core/rendering/Renderer.hpp"
#include "mge/config.hpp"

std::unordered_map<std::string, Texture*> Texture::textures = std::unordered_map<std::string, Texture*>();

Texture::Texture() : _id() {
	glGenTextures(1, &_id);
	textureData = new sf::Image();
}

Texture::~Texture()
{
	glDeleteTextures(1, &_id);
}

Texture* Texture::generateTexture(Texture* container, GLsizei width, GLsizei height, const void* data, GLenum format, GLint wrap, std::vector<const void*> mipmapData)
{
	glBindTexture(GL_TEXTURE_2D, container->getId());

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

	for (GLint i = 0; i < (GLint)mipmapData.size(); i++)
		glTexImage2D(GL_TEXTURE_2D, i + 1, format, width, height, 0, format, GL_UNSIGNED_BYTE, mipmapData[i]);

	if (wrap != 0)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
	}

	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	Renderer::CheckErrors(__func__, __LINE__);

	glBindTexture(GL_TEXTURE_2D, 0);

	return container;
}

GLuint Texture::getId() {
	return _id;
}

Texture* Texture::load(const std::string & pTexturePath, std::vector<std::string> pMipmaps, GLint wrap)
{
	if (textures[pTexturePath] != nullptr)
		if (textures[pTexturePath]->mipmaps == pMipmaps.size() && textures[pTexturePath]->_wrap == wrap)
			return textures[pTexturePath];

	Texture* texture = new Texture();

	// load from file and store in cache
	if (!texture->textureData->loadFromFile(pTexturePath)) {
		texture->textureData->loadFromFile(config::MGE_TEXTURE_PATH + "missing-texture.png");
	}

	//normal image 0,0 is top left, but opengl considers 0,0 to be bottom left, so we flip the image internally
	texture->textureData->flipVertically();

	std::vector<const void*> mipmapData = std::vector<const void*>();
	for (unsigned i = 0; i < pMipmaps.size(); i++)
	{
		sf::Image mipmap;
		if (!mipmap.loadFromFile(pMipmaps[i])) {
			mipmap.loadFromFile(config::MGE_TEXTURE_PATH + "missing-texture.png");
		}

		//normal image 0,0 is top left, but opengl considers 0,0 to be bottom left, so we flip the image internally
		mipmap.flipVertically();

		mipmapData.push_back(mipmap.getPixelsPtr());
	}

	return generateTexture(texture, texture->textureData->getSize().x, texture->textureData->getSize().y, texture->textureData->getPixelsPtr(), GL_RGBA, wrap, mipmapData);
}

// importer for textures
Texture* Texture::load(const std::string& pFilename, GLint wrap)
{
	if (textures[pFilename] != nullptr)
		if (textures[pFilename]->_wrap == wrap)
			return textures[pFilename];

	Texture* texture = new Texture();

	// load from file and store in cache
	if (!texture->textureData->loadFromFile(pFilename)) {
		texture->textureData->loadFromFile(config::MGE_TEXTURE_PATH + "missing-texture.png");
	}

	//normal image 0,0 is top left, but opengl considers 0,0 to be bottom left, so we flip the image internally
	texture->textureData->flipVertically();

	return generateTexture(texture, texture->textureData->getSize().x, texture->textureData->getSize().y, texture->textureData->getPixelsPtr(), GL_RGBA, wrap);
}

Texture * Texture::createEmpty(GLsizei width, GLsizei height, GLenum format, GLint mipmaps, GLint wrap)
{
	std::vector<const void*> mipmapData = std::vector<const void*>();
	for (int i = 0; i < mipmaps; i++)
		mipmapData.push_back(NULL);

	Texture* texture = new Texture();
	return generateTexture(texture, width, height, NULL, format, wrap, mipmapData);
}

sf::Image* Texture::getImageData()
{
	return textureData;
}










