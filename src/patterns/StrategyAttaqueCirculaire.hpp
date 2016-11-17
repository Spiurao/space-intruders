#pragma once

#include "StrategyAttaque.hpp"

class StrategyAttaqueCirculaire : public StrategyAttaque {
public:
	StrategyAttaqueCirculaire();
	~StrategyAttaqueCirculaire();
	std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend);
};