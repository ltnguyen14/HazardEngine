#include "vertexBuffer.h"
#include <GL/glew.h>
#include "../util/errorLogging.h"


VertexBuffer::VertexBuffer(const void * data, unsigned int size)
{
	GLCALL(glGenBuffers(1, &m_id));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCALL(glDeleteBuffers(1, &m_id));
}

void VertexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}

void VertexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
