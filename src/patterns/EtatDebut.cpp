#include "EtatDebut.hpp"
#include "../entitees/Boss.hpp"

EtatDebut::EtatDebut(Boss* b): EtatBoss(b)
{}

void EtatDebut::devenirSerieux(){
	b_->changerEtatSerieux();
}

void EtatDebut::devenirTresSerieux()
{}

void EtatDebut::devenirFurax()
{}

std::vector<Projectile*> EtatDebut::attaquer(SDL_Renderer *rend){
	if(delay_<=0){
		delay_ = 400;
		SDL_Rect bossRect = b_->getRect();
		std::vector<Projectile*> aReturn = std::vector<Projectile*>();
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 0, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		return aReturn;
	}
	else
		--delay_;

	return std::vector<Projectile*>();
}