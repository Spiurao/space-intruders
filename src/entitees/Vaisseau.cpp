#include <iostream>
#include "Vaisseau.hpp"

using namespace std;

Vaisseau::Vaisseau(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend) :
x_(x), y_(y), rayon_(rayon), img_(img), tex_(SDL_CreateTextureFromSurface(rend, img_))
{}

Vaisseau::~Vaisseau(){}

void Vaisseau::bouger(double x, double y){
	x_+=x;
	y_+=y;
	updateRect();
}

SDL_Texture *Vaisseau::getTexture(){
	return tex_;
}

SDL_Rect Vaisseau::getRect(){
	return rect_;
}

double Vaisseau::getRayon(){
	return rayon_;
<<<<<<< HEAD
}

std::vector<Projectile*>& Vaisseau::getProjectiles(){
	return vp_;
}

bool Vaisseau::estSorti(int w, int h){
    return x_+rayon_ < 0 || x_>w || y_>h;
}

void Vaisseau::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
=======
}
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba
