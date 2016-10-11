#include "Niveau1.hpp"

Niveau1::Niveau1(SpaceIntruders *jeu):
Niveau(jeu),
joueur_(Joueur(jeu->getW()/2.0, jeu->getH()/6.0, 8.0,
	SDL_LoadBMP("assets/vaisseau.bmp"),
	      jeu->getRenderer(), 5
	      )
	)
{
	ennemis = new std::vector<Ennemi>();
}

Niveau1::~Niveau1()
{}

void Niveau1::keysDown(std::map<double,bool> &k){
	if(k[SDLK_LSHIFT])
		joueur_.setVitesse(0.1);
	joueur_.deplacer(k);
}

void Niveau1::keysHold(std::map<double,bool> &k){

}

void Niveau1::keysUp(std::map<double,bool> &k){
	if(k[SDLK_LSHIFT])
		joueur_.setVitesse(0.2);
}