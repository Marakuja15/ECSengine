// ECSengine.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "ECSengine.h"
#include "raylib.h"

using namespace std;

int main()
{
    
    InitWindow(800, 450, "Dziala!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Raylib dziala!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
