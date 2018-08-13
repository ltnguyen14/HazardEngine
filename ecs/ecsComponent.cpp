#include "ecsComponent.h"

static unsigned int componentID = 0;

uint32 BaseECSComponent::nextID()
{
	return componentID++;
}
