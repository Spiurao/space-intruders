#include "EtatFurax.hpp"
#include "../entitees/Boss.hpp"

EtatFurax::EtatFurax(Boss* b): EtatBoss(b)
{}

void EtatFurax::devenirSerieux()
{}

void EtatFurax::devenirTresSerieux()
{}

void EtatFurax::devenirFurax()
{}

std::vector<Projectile*> EtatFurax::attaquer(SDL_Renderer *rend){
	SDL_Rect bossRect = b_->getRect();
	std::vector<Projectile*> aReturn = std::vector<Projectile*>();
	aReturn.push_back(new ProjectileJoueur(bossRect.x, bossRect.y, 10, 0, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));

	return aReturn;
}