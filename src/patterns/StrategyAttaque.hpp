#pragma once

/*!
 * \file StrategyAttaque.hpp
 * \brief Classe abstraite servant au pattern Strategy
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include <vector>
#include "../entitees/ProjectileJoueur.hpp"
#include "SDL2/SDL.h"

/*!
 * \class StrategyAttaque
 * \brief Classe représentant la stratégie d'un sbire
 */
class StrategyAttaque {
public:
	StrategyAttaque();
	virtual ~StrategyAttaque();
	virtual std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend) = 0;
};