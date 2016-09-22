#include <iostream>
#include "joueur.hpp"

using namespace std;

Joueur::Joueur(int x, int y, int lives): Vaisseau(x, y), lives_(lives)
{}

Joueur::~Joueur()
{}

void Joueur::afficher(){
    cout << '(' << x_ << ", " << y_ << ") ; " << lives_ << endl;
}
