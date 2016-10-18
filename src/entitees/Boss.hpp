#pragma once
#include "Ennemi.hpp"

class Boss : public Ennemi {
	
	public:
		Boss(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
		~Boss();
		void afficher();
};
