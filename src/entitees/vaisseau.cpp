#include <iostream>
#include "vaisseau.hpp"

using namespace std;

Vaisseau::Vaisseau(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend) :
x_(x), y_(y), rayon_(rayon), img_(img), tex_(SDL_CreateTextureFromSurface(rend, img_))
{}

Vaisseau::~Vaisseau(){}

//void Vaisseau::afficher(){}

void Vaisseau::bouger(double x, double y){
	x_+=x;
	y_+=y;
}