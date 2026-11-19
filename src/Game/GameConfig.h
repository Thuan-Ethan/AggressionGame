#pragma once
#include <vector>
#include "raylib.h"
#include "Building/CastleConfig.h"

class Game
{
public:
    Game();

    void Update(float dt);
    void Draw() const;

private:
    // Trạng thái của game
    Camera2D camera{};
    std::vector<Castle> castles;

    // Hàm hỗ trợ
    void UpdateCamera();
    void DrawWorld() const;
    void DrawCastles() const;
};