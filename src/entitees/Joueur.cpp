#include "Joueur.hpp"

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies), vitesse_(0.2), delay_(0)
{
	rect_.h = rect_.w = 64;
	rect_.x = x_;
	rect_.y = y_;

	vp_ = std::vector<Projectile*>();

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

Projectile* Joueur::tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend){
	return new ProjectileJoueur(x, y, 15, angle, vitesse, SDL_LoadBMP("assets/bullet.bmp"), rend);
}

void Joueur::gererJoueur(std::map<double, bool> &k, SDL_Renderer *rend, int FenetreH, int FenetreW){
	gererProjectiles();
	gererVitesse(k);
	deplacer(k, FenetreH, FenetreW);
	if(delay_ <= 0){
		if(k[SDLK_z]){
			vp_.push_back(tirer(x_, y_, 180, 1.5, rend));
			vp_.push_back(tirer(x_+44, y_, 180, 1.5, rend));
			delay_ = 60;
		}
	}
	delay_--;
}

void Joueur::gererProjectiles(){
	for(auto p: vp_)
		p->avancer();
}

void Joueur::afficher(){
    std::cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << std::endl;
}

<<<<<<< HEAD
/*
=======
std::vector<Projectile*>& Joueur::getProjectiles(){
	return vp_;
}

>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba
void Joueur::updateRect(){
	rect_.x = (int)x_;
	rect_.y = (int)y_;
}*/
