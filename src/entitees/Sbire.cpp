#include "Sbire.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

Sbire::Sbire(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp): Ennemi(x, y, rayon, img, rend, hp), delay_(0)
{
	rect_.h = rect_.w = 40;
	rect_.x = x_;
	rect_.y = y_;
	srand(time(NULL));
	if(rand()%2)
		attaque_ = new StrategyAttaqueCirculaire();
	else
		attaque_ = new StrategyAttaqueVerticalDescendant();
}

Sbire::~Sbire()
{}

vector<Projectile*> Sbire::attaquer(SDL_Renderer *rend){
	if(delay_ <= 0){
		delay_ = 600;
		vector<Projectile*> aReturn = attaque_->attaquer(rect_.x, rect_.y, rend);
		//delete attaque_;
		//attaque_ = new StrategyAttaqueVerticalDescendant();
		return aReturn;
	}
	else
		delay_--;

	return vector<Projectile*>();
}

void Sbire::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl; 
}
