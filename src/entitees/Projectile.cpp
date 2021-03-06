#include "Projectile.hpp"

Projectile::Projectile(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend) :
x_(x), y_(y), rayon_(rayon), angle_(angle), vitesse_(vitesse), img_(img), tex_(SDL_CreateTextureFromSurface(rend, img_))
{}

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

void Projectile::avancer(float delta){
	x_+=sin(angle_*M_PI/180.0)*vitesse_*delta*500;
	y_+=cos(angle_*M_PI/180.0)*vitesse_*delta*500;

	updateRect();
}

bool Projectile::estSorti(int w, int h){
    return x_+rayon_ < 0 || x_>w || y_>h || y_+rayon_ < 0;
}

void Projectile::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
