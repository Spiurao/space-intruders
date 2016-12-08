#include "EtatTresSerieux.hpp"
#include "../entitees/Boss.hpp"
#include <stdlib.h>
#include <time.h>

EtatTresSerieux::EtatTresSerieux(Boss* b): EtatBoss(b), angle_(0)
{
	srand((time(NULL)));
}

void EtatTresSerieux::devenirSerieux()
{}

void EtatTresSerieux::devenirTresSerieux()
{}

void EtatTresSerieux::devenirFurax()
{
	b_->changerEtatSerieux();
}

std::vector<Projectile*> EtatTresSerieux::attaquer(SDL_Renderer *rend){
	if(delay_<=0){
		delay_ = 10;
		SDL_Rect bossRect = b_->getRect();
		std::vector<Projectile*> aReturn = std::vector<Projectile*>();
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 90+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 180+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 270+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		angle_+=10+rand()%20;
		return aReturn;
	}
	else
		--delay_;

	return std::vector<Projectile*>();
}