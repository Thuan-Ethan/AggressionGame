#pragma once
#include "raylib.h"

//#include "World/WorldConfig.h"
constexpr float MAIN_CASTLE_WIDTH = 200.0f;
constexpr float MAIN_CASTLE_HEIGHT = 150.0f;
constexpr float CASTLE_MARGIN = 80.0f;

// Define the factions in the game
enum class Faction {
	Player,
	Enemy,
	Neutral
};


struct Castle
{
    // Position and size of the castle area
    Rectangle bounds;

    // Castle owner
    Faction faction;

    // Current health
    float health;

    // Is this a main castle?
    bool isMainCastle;

    // Constructor
    Castle(
        Rectangle bounds,
        Faction faction,
        float health,
        bool isMain
    );

    // Draw castle based on its faction
    void Draw() const;
};