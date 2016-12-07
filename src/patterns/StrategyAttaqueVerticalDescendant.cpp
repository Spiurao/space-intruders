#include "StrategyAttaqueVerticalDescendant.hpp"

using namespace std;

StrategyAttaqueVerticalDescendant::StrategyAttaqueVerticalDescendant()
{}

StrategyAttaqueVerticalDescendant::~StrategyAttaqueVerticalDescendant()
{}

std::vector<Projectile*> StrategyAttaqueVerticalDescendant::attaquer(int x, int y, SDL_Renderer *rend){
	vector<Projectile*> aReturn = vector<Projectile*>();
	aReturn.push_back(new ProjectileJoueur(x+10, y+10, 10, 0, 0.2, SDL_LoadBMP("assets/bullet.bmp"), rend));
	return aReturn;
}