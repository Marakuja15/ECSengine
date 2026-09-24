#pragma once
#include <vector>
#include <memory>
#include "World.h"
#include "System.h"
enum class SystemPhase {
	Update,
	Render
};
class SystemManager {
public:
	void RegisterSystem(std::unique_ptr<ISystem> system, SystemPhase phase) {
		if(phase == SystemPhase::Update)
			updateSystems.push_back(std::move(system));
		if(phase == SystemPhase::Render)
			renderSystems.push_back(std::move(system));
		
	}
	void UpdateAll(World& world) {
		for (auto& system : updateSystems) {
			system->Update(world);
		}
	}
	void RenderAll(World& world) {
		for (auto& system : renderSystems) {
			system->Update(world);
		}
	}
private:
	
	std::vector<std::unique_ptr<ISystem>> updateSystems;
	std::vector<std::unique_ptr<ISystem>> renderSystems;


};