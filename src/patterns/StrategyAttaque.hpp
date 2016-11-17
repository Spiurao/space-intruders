#pragma once

#include <vector>
#include "../entitees/ProjectileJoueur.hpp"
#include "SDL2/SDL.h"

class StrategyAttaque {
public:
	StrategyAttaque();
	virtual ~StrategyAttaque();
	virtual std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend) = 0;
};