#pragma once

#include "ecsComponent.h"

class BaseECSSystem {
public:
	BaseECSSystem(const std::vector<uint32>& componentTypesIn) : componentTypes(componentTypesIn) {}
	virtual void updateComponents(float delta, BaseECSComponent** components) {};
	const std::vector<uint32>& getComponentTypes() {
		return componentTypes;
	}

private:
	std::vector<uint32> componentTypes;
};