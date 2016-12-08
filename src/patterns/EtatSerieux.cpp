#include "EtatSerieux.hpp"
#include "../entitees/Boss.hpp"

EtatSerieux::EtatSerieux(Boss* b): EtatBoss(b)
{}

void EtatSerieux::devenirSerieux()
{}

void EtatSerieux::devenirTresSerieux()
{
	b_->changerEtatSerieux();
}

void EtatSerieux::devenirFurax()
{}

std::vector<Projectile*> EtatSerieux::attaquer(SDL_Renderer *rend){
	SDL_Rect bossRect = b_->getRect();
	std::vector<Projectile*> aReturn = std::vector<Projectile*>();
	aReturn.push_back(new ProjectileJoueur(bossRect.x, bossRect.y, 10, 0, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));

	return aReturn;
}