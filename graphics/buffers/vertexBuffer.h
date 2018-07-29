#pragma once

class VertexBuffer {
public:
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer() : m_id(0) {};

	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	unsigned int m_id;

};