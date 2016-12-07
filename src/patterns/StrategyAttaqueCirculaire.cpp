#include "StrategyAttaqueCirculaire.hpp"

using namespace std;

StrategyAttaqueCirculaire::StrategyAttaqueCirculaire()
{}

StrategyAttaqueCirculaire::~StrategyAttaqueCirculaire()
{}

std::vector<Projectile*> StrategyAttaqueCirculaire::attaquer(int x, int y, SDL_Renderer *rend){
	vector<Projectile*> aReturn = vector<Projectile*>();

	for(int i=0; i<10; ++i)
		aReturn.push_back(new ProjectileJoueur(x+10, y+10, 10, 36*i, 0.2, SDL_LoadBMP("assets/bullet.bmp"), rend));

	return aReturn;
}