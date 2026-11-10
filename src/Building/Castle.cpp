#include"CastleConfig.h"

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