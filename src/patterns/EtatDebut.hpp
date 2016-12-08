#pragma once
#include "EtatBoss.hpp"

class EtatDebut : public EtatBoss {
public:
	EtatDebut(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
};