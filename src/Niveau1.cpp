#include "Niveau1.hpp"

Niveau1::Niveau1(SpaceIntruders *jeu):
	Niveau(jeu),
	joueur_(Joueur(jeu->getW()/2.0-32, 5*jeu->getH()/6.0, 8.0,
			SDL_LoadBMP("assets/vaisseau.bmp"),
		    jeu->getRenderer(), 5
		    )
		)
{
	ennemis_ = std::vector<Ennemi*>();
	ennemis_.push_back(new Sbire(jeu->getW()/2-20, jeu->getH()/3, 40, SDL_LoadBMP("assets/sbirampon.bmp"), jeu->getRenderer(), 20));
}

Niveau1::~Niveau1()
{
	for(auto e: ennemis_)
		delete e;
}

void Niveau1::update(float delta){
	std::vector<Projectile*>& projectilesJoueur = joueur_.getProjectiles();

	for(int i=projectilesJoueur.size()-1; i>=0; --i){
		SDL_Rect rectProjectile = projectilesJoueur[i]->getRect();

		for(int j=ennemis_.size()-1; j>=0; --j){

			SDL_Rect rectEnnemi = ennemis_[j]->getRect();

			if(sqrt((rectProjectile.x-rectEnnemi.x)*(rectProjectile.x-rectEnnemi.x)
				+(rectProjectile.y-rectEnnemi.y)*(rectProjectile.y-rectEnnemi.y))
				< ennemis_[j]->getRayon()+projectilesJoueur[i]->getRayon()){

				ennemis_[j]->recevoirDommage(1);
				
				delete projectilesJoueur[i];
				projectilesJoueur.erase(projectilesJoueur.begin()+i);
			}

			if(ennemis_[j]->estMort()){
				delete ennemis_[j];
				ennemis_.erase(ennemis_.begin()+j);
			}
		}
	}
	for(auto e: ennemis_){
			e->tirer(e->getRect().x, e->getRect().y, 0, 0.1, jeu_->getRenderer());
		for(auto pe: e->getProjectiles())
			pe->avancer();
	}
}

void Niveau1::render(float delta, SDL_Renderer *rendu){
	SDL_Rect rectJoueur = joueur_.getRect();
	SDL_RenderCopy(jeu_->getRenderer(), joueur_.getTexture(), NULL, &rectJoueur);

	for(auto e: ennemis_){
		SDL_Rect rectEnnemi = e->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), e->getTexture(), NULL, &rectEnnemi);

		for(auto pe : e->getProjectiles()){
			SDL_Rect rectProjectileEnnemi = pe->getRect();
			SDL_RenderCopy(jeu_->getRenderer(), pe->getTexture(), NULL, &rectProjectileEnnemi);
		}
	}

	for(auto p: joueur_.getProjectiles()){
		SDL_Rect rectProjectile = p->getRect();
		SDL_RenderCopy(jeu_->getRenderer(), p->getTexture(), NULL, &rectProjectile);
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