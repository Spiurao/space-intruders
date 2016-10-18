#include "Joueur.hpp"

using namespace std;

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies), vitesse_(0.2)
{
	rect_.h = rect_.w = 64;
	rect_.x = x_;
	rect_.y = y_;
}

Joueur::~Joueur()
{}

void Joueur::retirerVie(){
    vies_--;
}

void Joueur::ajouterVie(){
    vies_++;
}

void Joueur::setVitesse(double v){
	vitesse_ = v;
}

void Joueur::deplacer(std::map<double, bool> &k){
	if(k[SDLK_UP])
		bouger(0.0, -vitesse_);
	if(k[SDLK_DOWN])
		bouger(0.0, vitesse_);
	if (k[SDLK_RIGHT])
		bouger(vitesse_,0.0);
	if (k[SDLK_LEFT])
		bouger(-vitesse_,0.0);

	updateRect();
}


void Joueur::afficher(){
    std::cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << std::endl;
}

void Joueur::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
