#include <iostream>
#include "Sbire.hpp"

using namespace std;

Sbire::Sbire(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp): Ennemi(x, y, rayon, img, rend, hp)
{
	rect_.h = rect_.w = 40;
	rect_.x = x_;
	rect_.y = y_;

}

Sbire::~Sbire()
{}

vector<Projectile*> Sbire::attaquer(SDL_Renderer *rend){
	vector<Projectile*> aReturn = vector<Projectile*>();

	for(int i=0; i<10; ++i)
		aReturn.push_back(tirer(rect_.x, rect_.y, 36*i, 1, rend));

	return aReturn;
}

void Sbire::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl; 
}
