#pragma once
#include "EntityManager.h"
#include "ComponentManager.h"
class ISystem {
public:
	virtual ~ISystem() = default;
	virtual void Update(EntityManager &entityManager, ComponentManager &componentManager) = 0;
};