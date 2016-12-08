#include "Niveau1.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

Niveau1::Niveau1(SpaceIntruders *jeu):
	Niveau(jeu),
	vague_(5, Vague::FLECHE, jeu),
	joueur_(Joueur(jeu->getW()/2.0-32, 5*jeu->getH()/6.0, 8.0,
				   SDL_LoadBMP("assets/vaisseau.bmp"),
		    	   jeu->getRenderer(), 20
		    	  )
			)

{

	//initialisation de la fenêtre
	rect_.x = 0, rect_.y = 0;
	rect_.w = jeu->getW();rect_.h=jeu->getH();
	imgBg_ = SDL_LoadBMP("assets/background.bmp");
	texBg_ = SDL_CreateTextureFromSurface(jeu->getRenderer(), imgBg_);

	//attributs pour les vagues
	tempsVague_ = 0;
	intervalVagues_ = 7;
	srand (time(NULL));

	//projectiles ennemis
	vpe_ = vector<Projectile*>();


	lifeBar_ = new LifeBar(&joueur_, jeu);

}

Niveau1::~Niveau1()
{
	//suppression des projectiles
	for(auto pe: vpe_)
		delete pe;
}

void Niveau1::update(float delta){

	tempsVague_ += delta;

	vector<Projectile*>& projectilesJoueur = joueur_.getProjectiles();

	//vérification des collisions entre les projectiles du joueur et les ennemis
	for(int i=projectilesJoueur.size()-1; i>=0; --i){

		SDL_Rect rectProjectile = projectilesJoueur[i]->getRect();

		int j = vague_.getNbEnnemis()-1;
		bool aTouche = false;
		while(j>=0 && !aTouche){

			SDL_Rect rectEnnemi = vague_.getEnnemi(j)->getRect();

			//Vérification si le boss est apparu
			if(!bossApparu_){
				if((rectProjectile.x-rectEnnemi.x)*(rectProjectile.x-rectEnnemi.x)
					+(rectProjectile.y-rectEnnemi.y)*(rectProjectile.y-rectEnnemi.y)
					< (vague_.getEnnemi(j)->getRayon()+projectilesJoueur[i]->getRayon())*
					(vague_.getEnnemi(j)->getRayon()+projectilesJoueur[i]->getRayon())){

					vague_.getEnnemi(j)->recevoirDommage(5);

					delete projectilesJoueur[i];
					projectilesJoueur.erase(projectilesJoueur.begin()+i);
					aTouche = true;
				}
			}
			//Vérification si vague de Sbire
			else{
				if((rectProjectile.x-rectEnnemi.x-64)*(rectProjectile.x-rectEnnemi.x-64)
					+(rectProjectile.y-rectEnnemi.y-45)*(rectProjectile.y-rectEnnemi.y-45)
					< (vague_.getEnnemi(j)->getRayon()+projectilesJoueur[i]->getRayon())*
					(vague_.getEnnemi(j)->getRayon()+projectilesJoueur[i]->getRayon())){

					vague_.getEnnemi(j)->recevoirDommage(5);

					delete projectilesJoueur[i];
					projectilesJoueur.erase(projectilesJoueur.begin()+i);
					aTouche = true;
				}
			}

			if(vague_.getEnnemi(j)->estMort()){
				vague_.deleteEnnemi(j);
			}
			--j;
		}
	}

	SDL_Rect rectJoueur = joueur_.getRect();

	//Vérification des collisions entre le joueur et les projectiles ennemis
	for(int i=vpe_.size()-1; i>=0; --i){

		SDL_Rect rectProjectileEnnemi = vpe_[i]->getRect();

		if((rectProjectileEnnemi.x-rectJoueur.x-16)*(rectProjectileEnnemi.x-rectJoueur.x-16)
			+(rectProjectileEnnemi.y-rectJoueur.y-16)*(rectProjectileEnnemi.y-rectJoueur.y-16)
			< (joueur_.getRayon()+vpe_[i]->getRayon())
			*(joueur_.getRayon()+vpe_[i]->getRayon())){

			joueur_.retirerVie();
			lifeBar_->update(delta);
			delete vpe_[i];
			vpe_.erase(vpe_.begin()+i);
		}
	}
	if(vague_.getNbEnnemis()>0){
		for(int i=0; i<vague_.getNbEnnemis(); ++i){
				vector<Projectile*> ennemiAttaque = vague_.getEnnemi(i)->attaquer(jeu_->getRenderer());
				vpe_.reserve(vpe_.size()+ennemiAttaque.size());
				vpe_.insert(vpe_.end(), ennemiAttaque.begin(), ennemiAttaque.end());
			}
	}

	//Mise à jour de la vague
	vague_.update(delta);

	//ajout d'une nouvelle vague
	if(tempsVague_ >= intervalVagues_ && nbVagues_ < maxVague_){
		vague_.add(rand() % 4 + 4, rand() % 3);
		tempsVague_ = 0;
		++nbVagues_;
	}

	//Apparition du boss si plus de vagues
	if(nbVagues_>=maxVague_ && !bossApparu_ && tempsVague_ >= intervalVagues_+5){
		vague_.add(1, 3);
		bossApparu_ = true;
	}

	//On avance chaque projectile ennemis
	for(auto pe: vpe_)
		pe->avancer(delta);

	joueur_.gererProjectiles(delta);

	//Vérification des conditions de défaite
	if(joueur_.estMort()){
		std::shared_ptr<GameOverScreen> gameOverScreen(new GameOverScreen(jeu_));
		jeu_->setScreen(gameOverScreen);
		jeu_->setInputListener(gameOverScreen);
	}
}

//Affichage
void Niveau1::render(float delta, SDL_Renderer *rendu){

	//SDL_Texture *globalTexture = SDL_CreateTexture(rendu, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, jeu_->getW(), jeu_->getH());
	/*SDL_SetRenderDrawColor(rendu,0,0,100,255);//FOND
	SDL_RenderFillRect(rendu, &rect_);*/
	SDL_RenderCopy(rendu, texBg_, 0, &rect_);

	//SDL_SetRenderTarget(rendu, globalTexture)

	for(auto pe : vpe_){
		SDL_Rect rectProjectileEnnemi = pe->getRect();
		SDL_RenderCopy(rendu, pe->getTexture(), NULL, &rectProjectileEnnemi);
	}

	for(auto p: joueur_.getProjectiles()){
		SDL_Rect rectProjectile = p->getRect();
		SDL_RenderCopy(rendu, p->getTexture(), NULL, &rectProjectile);
	}

	/*SDL_SetRenderTarget(rendu, NULL);
	SDL_Rect rectGlobalTexture; rectGlobalTexture.x = rectGlobalTexture.y = 0;
	rectGlobalTexture.h = jeu_->getH(); rectGlobalTexture.w = jeu_->getW();
	SDL_RenderCopy(rendu, globalTexture, NULL, &rectGlobalTexture);
	SDL_DestroyTexture(globalTexture);*/


	SDL_Rect rectJoueur = joueur_.getRect();
	SDL_RenderCopy(rendu, joueur_.getTexture(), NULL, &rectJoueur);

	vague_.render(delta, rendu);

	lifeBar_->render(delta);
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
