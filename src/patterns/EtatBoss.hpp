#pragma once

#include "SDL2/SDL.h"
#include "../entitees/ProjectileJoueur.hpp"
#include <vector>

class Boss;

class EtatBoss {
public:
	EtatBoss(Boss* b);
	virtual ~EtatBoss();
	virtual void devenirSerieux() = 0;
	virtual void devenirTresSerieux() = 0;
	virtual void devenirFurax() = 0;
	virtual std::vector<Projectile*> attaquer(SDL_Renderer *rend) = 0;
protected:
	Boss* b_;
	int delay_;
};