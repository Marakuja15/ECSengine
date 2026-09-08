#pragma once
#include <vector>
#include <algorithm>
#include "Entity.h"
class EntityManager {
public:
    Entity CreateEntity() {
        Entity id = nextEntityId++;
        entityVector.push_back(id);
        return id;
    }
    
    void RemoveEntity(Entity entity) {
        auto it = std::find(entityVector.begin(), entityVector.end(), entity);
        if (it != entityVector.end()) {
            entityVector.erase(it);
        }
    }
    const std::vector<Entity>& GetEntities() const {
        return entityVector;
    }
private:
   
    std::vector<Entity> entityVector;
    Entity nextEntityId = 0;


};