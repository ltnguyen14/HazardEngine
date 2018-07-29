#pragma once
#include <vec3.hpp>
#include "../buffers/vertexBuffer.h"
#include "../buffers/indexBuffer.h"
#include "../buffers/vertexBufferLayout.h"
#include "../buffers/vertexArray.h"

struct Entity {
	glm::vec3 position;
	glm::vec3 rotation;
};