
#include <iostream>
#include "raylib.h"
#include "World.h"
#include "SystemManager.h"

struct Position {
    float x;
    float y;
};
struct Velocity {
    float x;
    float y;
};

class MovementSystem : public ISystem {
public:
    void Update(World& world) override {
        for (auto entity : world.View<Position, Velocity>()) {
            Position* pos = world.GetComponent<Position>(entity);
            Velocity* vel = world.GetComponent<Velocity>(entity);
            pos->x += vel->x;
            pos->y += vel->y;
        }
    }
};

int main()
{
    InitWindow(800, 450, "ECS engine test");
    SetTargetFPS(60);

    World world;
    SystemManager systemManager;
    systemManager.RegisterSystem(std::make_unique<MovementSystem>());

    Entity player = world.CreateEntity();
    world.AddComponent(player, Position{ 400.0f, 225.0f });
    world.AddComponent(player, Velocity{ 1.0f, 0.5f });

    Entity staticThing = world.CreateEntity();
    world.AddComponent(staticThing, Position{ 100.0f, 100.0f });

    while (!WindowShouldClose())
    {
        systemManager.UpdateSystems(world);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto entity : world.View<Position>()) {
            Position* pos = world.GetComponent<Position>(entity);
            DrawCircle((int)pos->x, (int)pos->y, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}