#include <iostream>
#include "ennemi.hpp"

using namespace std;

Ennemi::Ennemi(int x, int y, int hp): Vaisseau(x, y), hp_(hp)
{}

Ennemi::~Ennemi()
{}

void Ennemi::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl; 
}

void Ennemi::recevoirDommage(int x){
    hp_-=x;
}
