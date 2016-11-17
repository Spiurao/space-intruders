#pragma once

#include "StrategyAttaque.hpp"

class StrategyAttaqueVerticalDescendant : public StrategyAttaque {
public:
	StrategyAttaqueVerticalDescendant();
	~StrategyAttaqueVerticalDescendant();
	std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend); 
};