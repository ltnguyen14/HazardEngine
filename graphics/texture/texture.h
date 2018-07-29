#pragma once

#include <string>

class Texture {
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	inline int getWidth() { return m_Width; };
	inline int getHeight() { return m_Height; };

private:
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	unsigned int m_id;
};