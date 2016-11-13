#include "Niveau1.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

Niveau1::Niveau1(SpaceIntruders *jeu):
	Niveau(jeu),
	vague_(5, Vague::FLECHE, jeu),
	joueur_(Joueur(jeu->getW()/2.0-32, 5*jeu->getH()/6.0, 8.0,
				   SDL_LoadBMP("assets/vaisseau.bmp"),
		    	   jeu->getRenderer(), 5
		    	  )
			)

{

	tempsVague_ = 0;
	intervalVagues_ = 7;
	srand (time(NULL));

	vpe_ = vector<Projectile*>();

}

Niveau1::~Niveau1()
{
	for(auto pe: vpe_)
		delete pe;
}

void Niveau1::update(float delta){

	tempsVague_ += delta;

	vector<Projectile*>& projectilesJoueur = joueur_.getProjectiles();

	for(int i=projectilesJoueur.size()-1; i>=0; --i){

		SDL_Rect rectProjectile = projectilesJoueur[i]->getRect();

		for(int j=vague_.getNbEnnemis()-1; j>=0; --j){

			SDL_Rect rectEnnemi = vague_.getEnnemi(j)->getRect();

			if(sqrt((rectProjectile.x-rectEnnemi.x)*(rectProjectile.x-rectEnnemi.x)
				+(rectProjectile.y-rectEnnemi.y)*(rectProjectile.y-rectEnnemi.y))
				< vague_.getEnnemi(j)->getRayon()+projectilesJoueur[i]->getRayon()){

				vague_.getEnnemi(j)->recevoirDommage(1);

				delete projectilesJoueur[i];
				projectilesJoueur.erase(projectilesJoueur.begin()+i);
			}

			if(vague_.getEnnemi(j)->estMort()){
				vague_.deleteEnnemi(j);
			}
		}
	}
	
	vague_.update(delta);

	if(tempsVague_ >= intervalVagues_){
		vague_.add(rand() % 4 + 4, rand() % 3);
		tempsVague_ = 0;
	}

	for(auto pe: vpe_)
		pe->avancer();
}

void Niveau1::render(float delta, SDL_Renderer *rendu){
	SDL_Rect rectJoueur = joueur_.getRect();
	SDL_RenderCopy(jeu_->getRenderer(), joueur_.getTexture(), NULL, &rectJoueur);

	vague_.render(delta, vpe_, rendu);

	for(auto pe : vpe_){
		SDL_Rect rectProjectileEnnemi = pe->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), pe->getTexture(), NULL, &rectProjectileEnnemi);
	}

	for(auto p: joueur_.getProjectiles()){
		SDL_Rect rectProjectile = p->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), p->getTexture(), NULL, &rectProjectile);
	}
}

void Niveau1::keysDown(map<double,bool> &k){
}

void Niveau1::keysHold(map<double,bool> &k){
	joueur_.gererJoueur(k, jeu_->getRenderer(), jeu_->getH(), jeu_->getW());
}

void Niveau1::keysUp(map<double,bool> &k){
	if(k[SDLK_RETURN]){
		shared_ptr<StartScreen> ss(new StartScreen(jeu_));
		jeu_->setScreen(ss);
		jeu_->setInputListener(ss);
	}
}
