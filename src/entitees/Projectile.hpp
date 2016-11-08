#pragma once

#include "SDL2/SDL.h"

class Projectile {
public:
	Projectile(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend);
	~Projectile();
	SDL_Texture *getTexture();
	SDL_Rect getRect();
	double getRayon();
	void avancer();
private:
	double x_, y_, rayon_;
	SDL_Rect rect_;
	SDL_Surface *img_;
	SDL_Texture *tex_;

	void updateRect();
};