    #include "raylib.h"
#include <iostream>
#include <array>
#include <cmath>     // fminf
#include <vector>

#pragma region imgui
#include "imgui.h"
#include "rlImGui.h"
#include "imguiThemes.h"
#pragma endregion

#include "World/WorldConfig.h"
#include "Building/CastleConfig.h"
#include "Game/GameConfig.h"

int main()
{
    InitWindow(800, 600, "Aggression Game");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    MaximizeWindow();
    SetTargetFPS(60);

    Game game;   // tạo SAU InitWindow

    while (!WindowShouldClose())
    {
        game.Update(GetFrameTime());
        game.Draw();


    }

    CloseWindow();
    return 0;
}
