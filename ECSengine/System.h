#pragma once
#include "World.h"
class World;
class ISystem {
public:
	virtual ~ISystem() = default;
	virtual void Update(World &world) = 0;
};