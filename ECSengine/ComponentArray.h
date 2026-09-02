#pragma once
#include<unordered_map>
#include"EntityManager.h"
class IComponentArray {
public:
	virtual ~IComponentArray() = default;
};
template<typename T>

class ComponentArray : public IComponentArray
{
public:
	void Add(Entity entity, T component)
	{
		componentMap[entity] = component;
	}
	T& Get(Entity entity)
	{
		return componentMap[entity];
	}
	bool Has(Entity entity)
	{
		return componentMap.find(entity) != componentMap.end();
	}
private:
	std::unordered_map<uint32_t, T> componentMap;
};