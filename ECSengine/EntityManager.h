#pragma once
#include <iostream>
#include <vector>
#include "ComponentManager.h"
using Entity = uint32_t;
class EntityManager {
public:
    Entity createEntity() {
        Entity id = nextEntityId++;
        entityVector.push_back(id);
        return id;
    }
    
    void removeEntity(Entity entity, ComponentManager& componentManager) {
        auto it = std::find(entityVector.begin(), entityVector.end(), entity);
        if (it != entityVector.end()) {
			componentManager.RemoveEntity(entity);
            entityVector.erase(it);
        }
    }
    const std::vector<Entity>& getEntities() const {
        return entityVector;
    }
private:
   
    std::vector<Entity> entityVector;
    Entity nextEntityId = 0;


};