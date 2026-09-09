#pragma once
#include "ComponentManager.h"
#include "EntityManager.h"

class World {
public:
	Entity CreateEntity() {
		return entityManager.CreateEntity();
	}
	void RemoveEntity(Entity entity) {
		componentManager.RemoveAllComponents(entity);
		entityManager.RemoveEntity(entity);
	}
	template<typename T>
	void AddComponent(Entity entity, T component) {
		componentManager.AddComponent(entity, component);
	}
	template<typename T>
	T* GetComponent(Entity entity) {
		return componentManager.GetComponent<T>(entity);
	}
	template<typename T>
	bool HasComponent(Entity entity) {
		return componentManager.HasComponent<T>(entity);
	}
	template<typename T>
	void RemoveComponent(Entity entity) {
		componentManager.RemoveComponent<T>(entity);
	}
	const std::vector<Entity>& GetEntities() const {
		return entityManager.GetEntities();
	}
	
	template<typename... Components>
	std::vector<Entity> View() {
		std::vector<Entity> result;
		for(auto entity : GetEntities())	{
			if ((HasComponent<Components>(entity) && ...)) {
				result.push_back(entity);
			}
		}
		return result;
	}
	void SetDeltaTime(float dt) {
		deltaTime = dt;
	}
	const float GetDeltaTime() const {
		return deltaTime;
	}
private:
	EntityManager entityManager;
	ComponentManager componentManager;
	float deltaTime = 0.0f;
};
