#include "EtatFurax.hpp"
#include "../entitees/Boss.hpp"

EtatFurax::EtatFurax(Boss* b): EtatBoss(b), delay_(0), angle_(0)
{}

void EtatFurax::devenirSerieux()
{}

void EtatFurax::devenirTresSerieux()
{}

void EtatFurax::devenirFurax()
{}

std::vector<Projectile*> EtatFurax::attaquer(SDL_Renderer *rend){
	
	std::vector<Projectile*> aReturn = std::vector<Projectile*>();
	if(delay_<=0){
		delay_ = 10;
		SDL_Rect bossRect = b_->getRect();
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 90+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 180+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 270+angle_, 0.5, SDL_LoadBMP("assets/bullet.bmp"), rend));

		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 45+angle_, 0.3, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 135+angle_, 0.3, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 225+angle_, 0.3, SDL_LoadBMP("assets/bullet.bmp"), rend));
		aReturn.push_back(new ProjectileJoueur(bossRect.x+64, bossRect.y+45, 10, 315+angle_, 0.3, SDL_LoadBMP("assets/bullet.bmp"), rend));


		angle_+=10+rand()%20;
		return aReturn;
	}
	else
		--delay_;

	return std::vector<Projectile*>();
}