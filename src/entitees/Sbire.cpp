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

void Sbire::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl; 
}
