#include "CastleConfig.h"
#include <algorithm>

Castle::Castle(
    Rectangle bounds,
    Faction faction,
    float health,
    bool isMainCastle
)
    : bounds(bounds),
    faction(faction),
    health(health),
    isMainCastle(isMainCastle)
{}

// Draw castle based on faction
void Castle::Draw() const
{
    // Calculate center position
    Vector2 center = {
        bounds.x + bounds.width / 2.0f,
        bounds.y + bounds.height / 2.0f
    };

    // Determine shape size
    float size = std::min(bounds.width, bounds.height);

    switch (faction)
    {
    case Faction::Player:
    {
        // Blue pentagon
        DrawPoly(
            center,
            5,
            size / 2.0f,
            -90.0f,
            BLUE
        );

        DrawPolyLines(
            center,
            5,
            size / 2.0f,
            -90.0f,
            DARKBLUE
        );

        break;
    }

    case Faction::Enemy:
    {
        // Red pentagon
        DrawPoly(
            center,
            5,
            size / 2.0f,
            -90.0f,
            RED
        );

        DrawPolyLines(
            center,
            5,
            size / 2.0f,
            -90.0f,
            MAROON
        );

        break;
    }

    case Faction::Neutral:
    {
        // Gray square
        Rectangle square = {
            center.x - size / 2.0f,
            center.y - size / 2.0f,
            size,
            size
        };

        DrawRectangleRec(square, GRAY);

        DrawRectangleLinesEx(
            square,
            3.0f,
            DARKGRAY
        );

        break;
    }
    }
}