#include <iostream>
#include <cmath>

#include "World/WorldConfig.h"
#include "Building/CastleConfig.h"
#include "GameConfig.h"

// Hàm vẽ một thành (chỉ dùng trong file này)
static void DrawCastle(const Castle& c)
{
    Color fill = GRAY;
    switch (c.faction)
    {
    case Faction::Player:  fill = BLUE; break;
    case Faction::Enemy:   fill = RED;  break;
    case Faction::Neutral: fill = GRAY; break;
    }

    DrawRectangleRec(c.bounds, fill);
    DrawRectangleLinesEx(c.bounds, c.isMainCastle ? 4.0f : 2.0f, BLACK);
}

Game::Game()
    : player({ CASTLE_MARGIN + MAIN_CASTLE_WIDTH + 50.0f, WORLD_HEIGHT / 2.0f })
{
    const float centerY = (WORLD_HEIGHT - MAIN_CASTLE_HEIGHT) / 2.0f;

    castles.emplace_back(
        Rectangle{ CASTLE_MARGIN, centerY, MAIN_CASTLE_WIDTH, MAIN_CASTLE_HEIGHT },
        Faction::Player, 1000.0f, true);

    castles.emplace_back(
        Rectangle{ WORLD_WIDTH - CASTLE_MARGIN - MAIN_CASTLE_WIDTH, centerY,
                   MAIN_CASTLE_WIDTH, MAIN_CASTLE_HEIGHT },
        Faction::Enemy, 1000.0f, true);
}

void Game::Update(float dt)
{
    player.Update(dt);
    UpdateCamera();
    // Sau này: cập nhật tướng, lính, thành...
}

void Game::UpdateCamera()
{
    camera.target = { WORLD_WIDTH / 2.0f, WORLD_HEIGHT / 2.0f };
    camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    camera.rotation = 0.0f;

    const float zoomX = (float)GetScreenWidth() / WORLD_WIDTH;
    const float zoomY = (float)GetScreenHeight() / WORLD_HEIGHT;
    camera.zoom = fminf(zoomX, zoomY);
}

void Game::Draw() const
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);
    DrawWorld();
    DrawCastles();
    player.Draw();
    // Sau này: DrawGeneral(); DrawUnits(); ...
    EndMode2D();

    DrawFPS(10, 10);   // UI vẽ ngoài BeginMode2D
    EndDrawing();
}

void Game::DrawWorld() const
{
    DrawRectangle(0, 0, WORLD_WIDTH, WORLD_HEIGHT, DARKBLUE);
    DrawRectangleLines(0, 0, WORLD_WIDTH, WORLD_HEIGHT, BLACK);

    DrawLine(WORLD_WIDTH / 2, 0, WORLD_WIDTH / 2, WORLD_HEIGHT, WHITE);
    DrawLine(0, WORLD_HEIGHT / 2, WORLD_WIDTH, WORLD_HEIGHT / 2, WHITE);
}

void Game::DrawCastles() const
{
    for (const Castle& c : castles)
        DrawCastle(c);
}

