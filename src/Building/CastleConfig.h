#pragma once
#include "raylib.h"

//#include "World/WorldConfig.h"

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
};