#pragma once
class IndexBuffer {
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	IndexBuffer() : m_id(0), m_count(0) {};
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int getCount() { return m_count; };

private:
	unsigned int m_id;
	unsigned int m_count;
};