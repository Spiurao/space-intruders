#include <iostream>
#include "Vaisseau.hpp"

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

SDL_Texture *Vaisseau::getTexture(){
	return tex_;
}

SDL_Rect Vaisseau::getRect(){
	return rect_;
}