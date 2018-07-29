#pragma once
#include <vector>
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexBufferLayout.h"

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind();
	void Unbind();

private:
	unsigned int m_vao;
};