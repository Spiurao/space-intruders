#pragma once
#include "EtatBoss.hpp"

class EtatSerieux : public EtatBoss {
public:
	EtatSerieux(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
private:
	int angle_;
};