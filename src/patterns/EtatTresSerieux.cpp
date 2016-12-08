#include "EtatTresSerieux.hpp"
#include "../entitees/Boss.hpp"

EtatTresSerieux::EtatTresSerieux(Boss* b): EtatBoss(b)
{}

void EtatTresSerieux::devenirSerieux()
{}

void EtatTresSerieux::devenirTresSerieux()
{}

void EtatTresSerieux::devenirFurax()
{
	b_->changerEtatSerieux();
}

std::vector<Projectile*> EtatTresSerieux::attaquer(SDL_Renderer *rend){
	SDL_Rect bossRect = b_->getRect();
	std::vector<Projectile*> aReturn = std::vector<Projectile*>();
	aReturn.push_back(new ProjectileJoueur(bossRect.x, bossRect.y, 10, 0, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));

	return aReturn;
}