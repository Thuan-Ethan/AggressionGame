#pragma once
#include "raylib.h"
#include <vector>

#include "Building/CastleConfig.h"
#include "Player/PlayerConfig.h"

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
    Player player;


    // Hàm hỗ trợ
    void UpdateCamera();
    void DrawWorld() const;
    void DrawCastles() const;
};