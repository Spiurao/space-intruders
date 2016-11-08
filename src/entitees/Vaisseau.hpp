#pragma once

#include <memory>
#include <vector>
#include "SDL2/SDL.h"
#include "Projectile.hpp"

class Vaisseau {
	public:
		Vaisseau(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend);
		virtual ~Vaisseau();
		virtual void afficher() = 0;
		virtual void tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend) = 0;
		void bouger(double x, double y);
		SDL_Texture *getTexture();
		SDL_Rect getRect();
		double getRayon();
		double getX();
		double getY();
		std::vector<Projectile*>& getProjectiles();

	protected:
		double x_, y_, rayon_;
		std::vector<Projectile*> vp_;
		SDL_Rect rect_;
		SDL_Surface *img_;
		SDL_Texture *tex_;
};

