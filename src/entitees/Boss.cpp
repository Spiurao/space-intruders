#include <iostream>
#include "Boss.hpp"

using namespace std;

Boss::Boss(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp): Ennemi(x, y, rayon, img, rend, hp), hpMax_(hp)
{
	rect_.h = 93;
	rect_.w = 128;
	rect_.x = x_;
	rect_.y = y_;
	etatDebut_ = new EtatDebut(this);
	etatSerieux_ = new EtatSerieux(this);
	etatTresSerieux_ = new EtatTresSerieux(this);
	etatFurax_ = new EtatFurax(this);
	etat_ = etatDebut_;
}

Boss::~Boss()
{
	delete etatDebut_;
	delete etatSerieux_;
	delete etatTresSerieux_;
	delete etatFurax_;
}

vector<Projectile*> Boss::attaquer(SDL_Renderer *rend)
{
	/*if(delay_ <= 0){
		delay_ = 600;*/
		return etat_->attaquer(rend);
	/*}
	else
		--delay_;

	return vector<Projectile*>();*/
}

void Boss::changerEtatSerieux(){
	etat_ = etatSerieux_;
}

void Boss::changerEtatTresSerieux(){
	etat_ = etatTresSerieux_;
}

void Boss::changerEtatFurax(){
	etat_ = etatFurax_;
}

void Boss::gererEtat(){
	if(hp_ <= 0.25*hpMax_)
		etat_->devenirFurax();
	else if(hp_ <= 0.5*hpMax_)
		etat_->devenirTresSerieux();
	else if(hp_ <= 0.75*hpMax_)
		etat_->devenirSerieux();
}

void Boss::afficher(){
	cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl;
}
