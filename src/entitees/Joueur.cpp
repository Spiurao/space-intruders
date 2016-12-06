#include "Joueur.hpp"

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies), vitesse_(0.2), delay_(0)
{
	rect_.h = rect_.w = 64;
	rect_.x = x_;
	rect_.y = y_;
	viesMax_ = vies;
	vp_ = std::vector<Projectile*>();

}

Joueur::~Joueur()
{}

void Joueur::retirerVie(){
    vies_--;
}

bool Joueur::estMort(){
	return vies_<=0;
}

void Joueur::ajouterVie(){
    vies_++;
}

int Joueur::getVies(){
	return vies_;
}
int Joueur::getViesMax(){
	return viesMax_;
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
	else
		--delay_;
}

void Joueur::gererProjectiles(){
	for(auto p: vp_)
		p->avancer();
}

void Joueur::afficher(){
    std::cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << std::endl;
}

std::vector<Projectile*>& Joueur::getProjectiles(){
	return vp_;
}
