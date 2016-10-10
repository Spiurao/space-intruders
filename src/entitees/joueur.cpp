#include <iostream>
#include "joueur.hpp"

using namespace std;

Joueur::Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies): Vaisseau(x, y, rayon, img, rend), vies_(vies)
{}

Joueur::~Joueur()
{}

void Joueur::retirerVie(){
    vies_--;
}

void Joueur::ajouterVie(){
    vies_++;
}

void Joueur::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << vies_ << " vies" << endl;
}
