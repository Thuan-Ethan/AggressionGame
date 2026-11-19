#include "PlayerConfig.h"
#include "raymath.h"
#include "World/WorldConfig.h"

Player::Player(Vector2 position)
    : position(position), radius(PLAYER_RADIUS), speed(PLAYER_SPEED), health(100.0f)
{}

void Player::PlayerMove() {
    Vector2 dir = { 0, 0 };

    if (IsKeyDown(KEY_W)) {
        dir.y += 1;
    }

    if (IsKeyDown(KEY_S)) {
        dir.y -= 1;
    }

    if (IsKeyDown(KEY_A)) {
        dir.x -= 1;
    }

    if (IsKeyDown(KEY_D)) {
        dir.x += 1;
    }

    if (dir.x != 0.0f || dir.y != 0.0f)
    {
        float length = sqrtf(
            dir.x * dir.x +
            dir.y * dir.y
        );

        dir.x /= length;
        dir.y /= length;
    }

    // Update Position
    position.x += dir.x * speed * deltaTime;
    position.y += dir.y * speed * deltaTime;
}

void Player::Update(float dt)
{
    // 1. Tạo Vector2 dir = {0, 0}
    // 2. Đọc phím WASD, cộng/trừ vào dir.x và dir.y
    // 3. Chuẩn hoá dir (nếu độ dài khác 0)
    // 4. Cập nhật position theo dir, speed, dt
    // 5. Giữ position trong thế giới

    PlayerMove();

}

void Player::Draw() const
{
    // Vẽ hình tròn tại position
}