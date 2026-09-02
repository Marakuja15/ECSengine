// ECSengine.cpp: definiuje punkt wejścia dla aplikacji.
//

#include <iostream>
#include "raylib.h"
#include "vector"
#include "unordered_map"
#include "EntityManager.h"
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

    for (const auto& entity : entities) {
        std::cout << entity << std::endl;
    }
    //
    //std::unique_ptr<IComponentArray> arr = std::make_unique<ComponentArray<Position>>();

    //// arr->Add(...) // BŁĄD: przez wąskie okno IComponentArray* nie widać Add()!


    //ComponentArray<Position>* realArr = static_cast<ComponentArray<Position>*>(arr.get());

    //realArr->Add(entity, somePosition);  // OK, teraz widać wszystkie metody

    
    return 0;
}
