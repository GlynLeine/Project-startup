#pragma once

#include <GL/glew.h>
#include "glm.hpp"

class Texture;

class FrameBuffer
{
public:
	FrameBuffer();
	~FrameBuffer();

	GLenum CheckStatus();
	void AttachTexture(GLenum attachment, Texture* texture, GLint mipmap = 0);
	void Bind();
	static void Unbind();

protected:
	GLuint bufferID;
};