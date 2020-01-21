#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <unordered_map>
#include <string>
#include <GL/glew.h>
#include <vector>


class Texture
{
public:
	static Texture* load(const std::string& pTexturePath, std::vector<std::string> pMipmaps, GLint wrap = GL_REPEAT);
	static Texture* load(const std::string& pTexturePath, GLint wrap = GL_REPEAT);
	static Texture* createEmpty(GLsizei width, GLsizei height, GLenum format = GL_RGBA, GLint mipmaps = 0, GLint wrap = 0);

	GLuint getId();

	static std::unordered_map<std::string, Texture*> textures;

protected:
	Texture();
	virtual ~Texture();

	static Texture* generateTexture(GLsizei width, GLsizei height, const void* data, GLenum format = GL_RGBA, GLint wrap = 0, std::vector<const void*> mipmapData = std::vector<const void*>());

	//OpenGL id for texture buffer
	GLuint _id;
	GLint _wrap;
	GLint mipmaps;
};

#endif // TEXTURE_HPP