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

void Ennemi::tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend){
	vp_.push_back(new ProjectileJoueur(x+10, y, 15, angle, vitesse, SDL_LoadBMP("assets/bullet.bmp"), rend));
}

bool Ennemi::estMort(){
	return hp_ <= 0;
}