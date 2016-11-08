#include "ProjectileJoueur.hpp"

ProjectileJoueur::ProjectileJoueur(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend) :
Projectile(x, y, rayon, angle, vitesse, img, rend){

	rect_.h = rect_.w = 20;
	rect_.x = x_;
	rect_.y = y_;
}

ProjectileJoueur::~ProjectileJoueur()
{}

SDL_Texture *ProjectileJoueur::getTexture(){
	return tex_;
}

SDL_Rect ProjectileJoueur::getRect(){
	return rect_;
}

double ProjectileJoueur::getRayon(){
	return rayon_;
}

void ProjectileJoueur::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
