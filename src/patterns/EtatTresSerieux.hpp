#pragma once
#include "EtatBoss.hpp"

class EtatTresSerieux : public EtatBoss {
public:
	EtatTresSerieux(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
};