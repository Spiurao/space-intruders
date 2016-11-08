#pragma once

#include "SDL2/SDL.h"
#include "Projectile.hpp"

class ProjectileJoueur: public Projectile {
public:
	ProjectileJoueur(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend);
	~ProjectileJoueur();
	SDL_Texture *getTexture();
	SDL_Rect getRect();
	double getRayon();
private:
	void updateRect();
};