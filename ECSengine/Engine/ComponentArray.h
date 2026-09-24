#pragma once
#include <unordered_map>
#include "Entity.h"
class IComponentArray {
public:
	virtual ~IComponentArray() = default;
	virtual void Remove(Entity entity) = 0;
};
template<typename T>

class ComponentArray : public IComponentArray
{
public:
	void Add(Entity entity, T component)
	{
		componentMap[entity] = component;
	}
	T* Get(Entity entity)
	{
		auto it = componentMap.find(entity);
		if (it == componentMap.end()) {
			return nullptr;
		}
		return &(it->second);
	}
	void Remove(Entity entity) override
	{	
		componentMap.erase(entity);
	}
	bool Has(Entity entity)
	{
		return componentMap.find(entity) != componentMap.end();
	}
private:
	std::unordered_map<uint32_t, T> componentMap;
};