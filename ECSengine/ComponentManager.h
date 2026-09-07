#pragma once
#include<iostream>
#include "ComponentArray.h"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "EntityManager.h"

class ComponentManager {
public:
    template<typename T>
    void AddComponent(T component, Entity entity) {
		ComponentArray<T>* arr = RequireComponentArray<T>();
		arr->Add(entity, component); 
    }
    template<typename T>
    T* GetComponent(Entity entity) {
		ComponentArray<T>* arr = GetComponentArray<T>();
        if (arr == nullptr) return nullptr;

		return arr->Get(entity);
    }
    template<typename T>
    bool HasComponent(Entity entity) {
        ComponentArray<T>* arr = GetComponentArray<T>();
        if (arr == nullptr) return false;
        return arr->Has(entity);
    }
	template<typename T>
    void RemoveComponent(Entity entity) {
        ComponentArray<T>* arr = GetComponentArray<T>();
		if (arr == nullptr) return;
        arr->Remove(entity);

	}

    void RemoveEntity(Entity entity) {
        for (auto& pair : componentArrays) {
            pair.second->Remove(entity);
		}
    }
private:
    template<typename T>
    ComponentArray<T>* RequireComponentArray() {
        auto it = componentArrays.find(std::type_index(typeid(T)));
        if (it != componentArrays.end()) {
            return static_cast<ComponentArray<T>*>(it->second.get());
        }

        std::unique_ptr<IComponentArray> arr = std::make_unique<ComponentArray<T>>();
        ComponentArray<T>* realArr = static_cast<ComponentArray<T>*>(arr.get());
        componentArrays[std::type_index(typeid(T))] = std::move(arr);
        return realArr;
    }
    template<typename T>
    ComponentArray<T>* GetComponentArray() {
        auto it = componentArrays.find(std::type_index(typeid(T)));
        if (it != componentArrays.end()) {
            return static_cast<ComponentArray<T>*>(it->second.get());
        }
        return nullptr;
    }

    std::unordered_map<std::type_index, std::unique_ptr<IComponentArray>> componentArrays;
};