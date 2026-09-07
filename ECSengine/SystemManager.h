#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "System.h"
class SystemManager {
public:
	void RegisterSystem(std::unique_ptr<ISystem> system) {
		systems.push_back(std::move(system));
	}
	void UpdateSystems(EntityManager &entityManager, ComponentManager &componentManager) {
		for (auto& system : systems) {
			system->Update(entityManager, componentManager);
		}
	}
private:
	
	std::vector<std::unique_ptr<ISystem>> systems;
};