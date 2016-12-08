#include "EtatSerieux.hpp"
#include "../entitees/Boss.hpp"

EtatSerieux::EtatSerieux(Boss* b): EtatBoss(b), angle_(0)
{}

void EtatSerieux::devenirSerieux()
{}

void EtatSerieux::devenirTresSerieux()
{
	b_->changerEtatTresSerieux();
}

void EtatSerieux::devenirFurax()
{}

std::vector<Projectile*> EtatSerieux::attaquer(SDL_Renderer *rend){
	if(delay_<=0){
		delay_ = 40;
		SDL_Rect bossRect = b_->getRect();
		std::vector<Projectile*> aReturn = std::vector<Projectile*>();
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 180+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 0+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		angle_+=14;
		return aReturn;
	}
	else
		--delay_;

	return std::vector<Projectile*>();
}