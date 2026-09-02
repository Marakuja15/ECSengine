#pragma once
#include <iostream>
#include <vector>
using Entity = uint32_t;
class EntityManager {
public:
    Entity createEntity() {
        Entity id = nextEntityId++;
        entityVector.push_back(id);
        return id;
    }
    const std::vector<Entity>& getEntities() const {
        return entityVector;
    }


private:
    std::vector<Entity> entityVector;
    Entity nextEntityId = 0;


};