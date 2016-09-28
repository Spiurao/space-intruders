#include <iostream>
#include "sbire.hpp"

using namespace std;

Sbire::Sbire(int x, int y, int hp): Ennemi(x, y, hp)
{}

Sbire::~Sbire()
{}

void Sbire::afficher(){
    cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl; 
}
