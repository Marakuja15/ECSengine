#pragma once
#include <vector>
#include <memory>
#include "System.h"
class SystemManager {
public:
	void RegisterSystem(std::unique_ptr<ISystem> system) {
		systems.push_back(std::move(system));
	}
	void UpdateSystems(World &world) {
		for (auto& system : systems) {
			system->Update(world);
		}
	}
private:
	
	std::vector<std::unique_ptr<ISystem>> systems;
};