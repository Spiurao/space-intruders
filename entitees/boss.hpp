#pragma once
#include "ennemi.hpp"

class Boss : public Ennemi {
	
	public:
		Boss(int x, int y, int hp);
		~Boss();
		void afficher();
};
