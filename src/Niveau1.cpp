#include "Niveau1.hpp"

Niveau1::Niveau1(SpaceIntruders *jeu):
	Niveau(jeu),
	joueur_(Joueur(jeu->getW()/2.0, jeu->getH()/6.0, 8.0,
			SDL_LoadBMP("assets/vaisseau.bmp"),
		    jeu->getRenderer(), 5
		    )
		)
{}

Niveau1::~Niveau1()
{}

void Niveau1::update(float delta){

}

void Niveau1::render(float delta, SDL_Renderer *rendu){
	SDL_Rect tmp = joueur_.getRect();
	SDL_RenderCopy(jeu_->getRenderer(), joueur_.getTexture(), NULL, &tmp);
	std::vector<Projectile*> projectilesJoueur = joueur_.getProjectiles();
	for(auto p : projectilesJoueur){
		SDL_Rect tmp = p->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), p->getTexture(), NULL, &tmp);
	}
}

void Niveau1::keysDown(std::map<double,bool> &k){
}

void Niveau1::keysHold(std::map<double,bool> &k){
	joueur_.gererJoueur(k, jeu_->getRenderer(), jeu_->getH(), jeu_->getW());
}

void Niveau1::keysUp(std::map<double,bool> &k){
	if(k[SDLK_RETURN]){
		std::shared_ptr<StartScreen> ss(new StartScreen(jeu_));
		jeu_->setScreen(ss);
		jeu_->setInputListener(ss);
	}
}