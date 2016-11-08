#include <iostream>
#include "Ennemi.hpp"

using namespace std;

Ennemi::Ennemi(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp):
Vaisseau(x, y, rayon, img, rend), hp_(hp)
{}

Ennemi::~Ennemi()
{}

void Ennemi::recevoirDommage(int x){
    hp_-=x;
}

bool Ennemi::estMort(){
	return hp_ <= 0;
}