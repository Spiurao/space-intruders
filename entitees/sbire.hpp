#pragma once

#include "ennemi.hpp"

class Sbire : public Ennemi {
	
	public:
		Sbire(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
		~Sbire();
		void afficher();
};
