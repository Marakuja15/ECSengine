#pragma once
#include <vector>
#include <algorithm>
#include "Entity.h"
class EntityManager {
public:
    Entity CreateEntity() {
        if (freeSlots.size() > 0){
			Entity entity = freeSlots.back();
			entity.generation++;
			entityVector[entity.id] = entity;
			freeSlots.pop_back();
            return entity;
        }
        else {
			uint32_t lastIndex = entityVector.size();
			Entity entity{ lastIndex, 0 };
			entityVector.push_back(entity);
            return entity;
        }
    }

    void RemoveEntity(Entity entity) {
        if(entityVector[entity.id].id == entity.id &&
            entityVector[entity.id].generation == entity.generation)
		freeSlots.push_back(entity);
    }
    bool IsAlive(Entity entity) {
    }
    std::vector<Entity> GetEntities()  {
		std::vector<Entity> aliveEntities;
		for (auto entity : entityVector) {
            if (IsAlive(entity)) {
                aliveEntities.push_back(entity);
            }
        }
        return aliveEntities;
     }
private:

    std::vector<Entity> entityVector;
    std::vector<Entity> freeSlots;
   

};