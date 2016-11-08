#include "Joueur.hpp"

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies), vitesse_(0.2), delay_(0)
{
	rect_.h = rect_.w = 64;
	rect_.x = x_;
	rect_.y = y_;
	vp_ = std::vector<Projectile*>();
}

Joueur::~Joueur(){
	for(auto p: vp_)
		delete p;
}

void Joueur::retirerVie(){
    vies_--;
}

void Joueur::ajouterVie(){
    vies_++;
}

void Joueur::setVitesse(double v){
	vitesse_ = v;
}

void Joueur::deplacer(std::map<double, bool> &k, int FenetreH, int FenetreW){
	if(k[SDLK_UP] && y_ > 0)
		bouger(0.0, -vitesse_);
	if(k[SDLK_DOWN] && y_ < FenetreH-64)
		bouger(0.0, vitesse_);
	if (k[SDLK_RIGHT] && x_ < FenetreW-64)
		bouger(vitesse_,0.0);
	if (k[SDLK_LEFT] && x_ > 0)
		bouger(-vitesse_,0.0);

	updateRect();
}

void Joueur::gererVitesse(std::map<double, bool> &k){
	if(k[SDLK_LSHIFT])
		setVitesse(0.2);
	else
		setVitesse(0.5);
}

void Joueur::tirer(SDL_Renderer *rend){
	vp_.push_back(new Projectile(x_, y_, 15, SDL_LoadBMP("assets/bullet.bmp"), rend));
	vp_.push_back(new Projectile(x_+44, y_, 15, SDL_LoadBMP("assets/bullet.bmp"), rend));
}

void Joueur::gererJoueur(std::map<double, bool> &k, SDL_Renderer *rend, int FenetreH, int FenetreW){
	gererProjectiles();
	gererVitesse(k);
	deplacer(k, FenetreH, FenetreW);
	if(delay_ <= 0){
		if(k[SDLK_z]){
			tirer(rend);
			delay_ = 60;
		}
	}
	delay_--;
}

std::vector<Projectile*>& Joueur::getProjectiles(){
	return vp_;
}

void Joueur::gererProjectiles(){
	for(auto p: vp_)
		p->avancer();
}

void Joueur::afficher(){
    std::cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << std::endl;
}


void Joueur::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}
