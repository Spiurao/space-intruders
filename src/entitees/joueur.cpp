#include <iostream>
#include "joueur.hpp"

using namespace std;

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies), vitesse_(0.2)
{}

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
		joueur_.bouger(0.0, vitesse_);
	if(k[SDLK_DOWN])
		joueur_.bouger(0.0, -vitesse_);
	if (k[SDLK_RIGHT])
		joueur_.bouger(vitesse_,0.0);
	if (k[SDLK_LEFT])
		joueur_.bouger(-vitesse_,0.0);
}

void Joueur::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << endl;
}
