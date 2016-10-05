#pragma once

#include <memory>
#include "SDL2/SDL.h"


class Vaisseau {
	public:
		Vaisseau(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend);
		~Vaisseau();
		virtual void afficher() = 0;
		void bouger(double x, double y);

	protected:
		double x_, y_, rayon_;
		SDL_Surface *img_;
		SDL_Texture *tex_;
};

