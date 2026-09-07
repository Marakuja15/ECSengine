// ECSengine.cpp: definiuje punkt wejścia dla aplikacji.
//

#include <iostream>
#include "raylib.h"
#include "vector"
#include "unordered_map"
#include "EntityManager.h"
#include "ComponentManager.h"
using namespace std;

struct Position {
    float x;
    float y;
};
struct Velocity {
    float x;
    float y;
};



int main()
{
	std::unique_ptr<EntityManager> entityManager = std::make_unique<EntityManager>();
    for (int i = 0; i < 10; ++i) {
        Entity id = entityManager->createEntity();
		
    }
	const auto& entities = entityManager->getEntities();
	std::unique_ptr<ComponentManager> componentManager = std::make_unique<ComponentManager>();
    componentManager->AddComponent(Position{ 10.0f, 5.0f }, entities[0]);
    for (const auto& entity : entities) {
        std::cout << entity << std::endl;
        
    }
    Position* pos = componentManager->GetComponent<Position>(entities[0]);
    if (pos != nullptr) {
		std::cout << pos->x << pos->y << std::endl;
        pos->x = 60.0f;
        std::cout << pos->x << pos->y << std::endl;
    }
    else {
		std::cout << "Position component not found for entity " << entities[0] << std::endl;
    }
    Position* pos2 = componentManager->GetComponent<Position>(entities[1]);
    if (pos2 != nullptr) {
        std::cout << pos2->x << pos2->y << std::endl;
       
    }
    else {
        std::cout << "Position component not found for entity " << entities[1] << std::endl;

    }
	bool has = componentManager->HasComponent<Position>(entities[0]);
	cout << "Entity " << entities[0] << " has Position component: " << (has ? "true" : "false") << std::endl;
	bool has2 = componentManager->HasComponent<Position>(entities[1]);
	cout << "Entity " << entities[1] << " has Position component: " << (has2 ? "true" : "false") << std::endl;

    //
    //std::unique_ptr<IComponentArray> arr = std::make_unique<ComponentArray<Position>>();

    //// arr->Add(...) // BŁĄD: przez wąskie okno IComponentArray* nie widać Add()!


    //ComponentArray<Position>* realArr = static_cast<ComponentArray<Position>*>(arr.get());

    //realArr->Add(entity, somePosition);  // OK, teraz widać wszystkie metody

    
    return 0;
}
