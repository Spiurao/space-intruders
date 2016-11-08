#include "Projectile.hpp"

Projectile::Projectile(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend) :
x_(x), y_(y), rayon_(rayon), img_(img), tex_(SDL_CreateTextureFromSurface(rend, img_)){

	rect_.h = rect_.w = 20;
	rect_.x = x_;
	rect_.y = y_;
}

Projectile::~Projectile()
{}

SDL_Texture *Projectile::getTexture(){
	return tex_;
}

SDL_Rect Projectile::getRect(){
	return rect_;
}

double Projectile::getRayon(){
	return rayon_;
}

void Projectile::avancer(){
	y_-=1.5;

	updateRect();
}

void Projectile::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
