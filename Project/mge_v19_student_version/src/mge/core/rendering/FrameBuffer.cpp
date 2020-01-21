#include "FrameBuffer.h"
#include "Texture.hpp"

FrameBuffer::FrameBuffer()
{
	glGenBuffers(1, &bufferID);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &bufferID);
}

GLenum FrameBuffer::CheckStatus()
{
	glBindFramebuffer(GL_FRAMEBUFFER, bufferID);
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	return status;
}

void FrameBuffer::AttachTexture(GLenum attachment, Texture * texture, GLint mipmap)
{
	glBindFramebuffer(GL_FRAMEBUFFER, bufferID);
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture->getId(), mipmap);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::Bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, bufferID);
}

void FrameBuffer::Unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
