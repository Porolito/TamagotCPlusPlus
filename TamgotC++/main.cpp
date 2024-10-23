// TamgotC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "raylib.h"
#include "Button.h"
#include "Tamagot.h"

int main() {

    Color Dark_Green = Color{ 20, 160, 133, 255 };
    const int screenWidth = 600;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    
    SetTargetFPS(60);

    StartButton startButton{"Assets/start_button.png",{100,100}, 3};

    Tamagot tamagot{ "Sasha","Assets/tama_neutral.png" };

    while (WindowShouldClose() == false) {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        startButton.isPressed(mousePosition, mousePressed);

        tamagot.Draw();
        tamagot.UpdateAnyMeter(1, '+');
        BeginDrawing();
        ClearBackground(Dark_Green);
        DrawRectangle(275,275, 100, 50, RED);
        startButton.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
