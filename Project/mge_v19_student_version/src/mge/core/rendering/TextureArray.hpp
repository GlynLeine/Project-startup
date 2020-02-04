#pragma once

#include <unordered_map>
#include <string>
#include <GL/glew.h>
#include <vector>
#include <SFML/Graphics.hpp>


class Texture;

class TextureArray
{
public:
	GLuint getId();

	template<unsigned int count>
	static TextureArray* generateTextureArray(std::array<Texture*, count> textures, bool wrap = true);

protected:
	TextureArray();
	virtual ~TextureArray();

	//OpenGL id for texture buffer
	GLuint _id;
};

template<unsigned int count>
inline TextureArray* TextureArray::generateTextureArray(std::array<Texture*, count> textures, bool wrap)
{
	TextureArray* textureArray = new TextureArray();

	glBindTexture(GL_TEXTURE_2D_ARRAY, textureArray->getId());
	sf::Image* firstTexture = textures[0]->getImageData();
	std::vector <sf::Uint8> imageData;

	for (int i = 0; i < count; i++)
	{
		const sf::Uint8* dataPtr = textures[i]->getImageData()->getPixelsPtr();
		unsigned area = textures[i]->getImageData()->getSize().x * textures[i]->getImageData()->getSize().y;
		std::vector<sf::Uint8> layer = std::vector<sf::Uint8>(dataPtr, dataPtr + (area*4));
		imageData.insert(imageData.end(), layer.begin(), layer.end());
	}

	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA, firstTexture->getSize().x, firstTexture->getSize().y, count, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());

	if (wrap != 0)
	{
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, wrap);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, wrap);
	}

	glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

	return textureArray;
}