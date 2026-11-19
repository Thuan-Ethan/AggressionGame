#pragma once
#include "raylib.h"

constexpr float PLAYER_RADIUS = 16.0f;
constexpr float PLAYER_SPEED = 250.0f;   // pixel mỗi giây

struct Player
{
    Vector2 position;
    float   radius;
    float   speed;
    float   health;

    Player(Vector2 position);

    void PlayerMove();

    void Update(float dt);
    void Draw() const;
};