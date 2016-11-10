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
<<<<<<< HEAD
	tempsVague_ = 0;
	intervalVagues_ = 7;
	srand (time(NULL));
=======
	ennemis_ = vector<Ennemi*>();
	vpe_ = vector<Projectile*>();
	ennemis_.push_back(new Sbire(jeu->getW()/3-20, jeu->getH()/3, 40, SDL_LoadBMP("assets/sbirampon.bmp"), jeu->getRenderer(), 20));
	ennemis_.push_back(new Sbire(2*jeu->getW()/3-20, jeu->getH()/3, 40, SDL_LoadBMP("assets/sbirampon.bmp"), jeu->getRenderer(), 20));
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba
}

Niveau1::~Niveau1()
{
<<<<<<< HEAD

}

void Niveau1::update(float delta){
	tempsVague_ += delta;
	std::vector<Projectile*>& projectilesJoueur = joueur_.getProjectiles();
=======
	for(auto e: ennemis_)
		delete e;

	for(auto pe: vpe_)
		delete pe;
}

void Niveau1::update(float delta){
	vector<Projectile*>& projectilesJoueur = joueur_.getProjectiles();
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba

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
<<<<<<< HEAD
	
	vague_.update(delta);

	if(tempsVague_ >= intervalVagues_){
		vague_.add(rand() % 4 + 4, rand() % 3);
		tempsVague_ = 0;
=======

	for(auto pe: vpe_)
		pe->avancer();

	if(delay<=0){
		for(auto e: ennemis_){
				vector<Projectile*> ennemiAttaque = e->attaquer(jeu_->getRenderer());
				vpe_.reserve(vpe_.size()+ennemiAttaque.size());
				vpe_.insert(vpe_.end(), ennemiAttaque.begin(), ennemiAttaque.end());
			}
		delay=50;
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba
	}
	
	delay--;
}

void Niveau1::render(float delta, SDL_Renderer *rendu){
	SDL_Rect rectJoueur = joueur_.getRect();
	SDL_RenderCopy(jeu_->getRenderer(), joueur_.getTexture(), NULL, &rectJoueur);

<<<<<<< HEAD
	vague_.render(delta, rendu);
=======
	for(auto e: ennemis_){
		SDL_Rect rectEnnemi = e->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), e->getTexture(), NULL, &rectEnnemi);
	}

	for(auto pe : vpe_){
		SDL_Rect rectProjectileEnnemi = pe->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), pe->getTexture(), NULL, &rectProjectileEnnemi);
	}
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba

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
