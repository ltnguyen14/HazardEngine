#include "indexBuffer.h"
#include <GL/glew.h>
#include "../util/errorLogging.h"

IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count)
	:m_count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLCALL(glGenBuffers(1, &m_id));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCALL(glDeleteBuffers(1, &m_id));
}

void IndexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}

void IndexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
