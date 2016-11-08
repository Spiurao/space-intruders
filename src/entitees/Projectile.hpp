#pragma once

#include <math.h>
#include "SDL2/SDL.h"

class Projectile {
public:
	Projectile(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend);
	virtual ~Projectile();
	SDL_Texture *getTexture();
	SDL_Rect getRect();
	double getRayon();
	void avancer();
protected:
	double x_, y_, rayon_, angle_, vitesse_;
	SDL_Rect rect_;
	SDL_Surface *img_;
	SDL_Texture *tex_;

	void updateRect();
};