#pragma once
#include "ennemi.hpp"

class Sbire : public Ennemi {
	
	public:
		Sbire(int x, int y, int hp);
		~Sbire();
		void afficher();
};
