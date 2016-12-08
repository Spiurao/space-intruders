#pragma once
#include "EtatBoss.hpp"

class EtatFurax : public EtatBoss {
public:
	EtatFurax(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
private:
	int delay_;
	int angle_;
};