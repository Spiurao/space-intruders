#include <iostream>
#include "boss.hpp"

using namespace std;

Boss::Boss(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp): Ennemi(x, y, rayon, img, rend, hp)
{}

Boss::~Boss()
{}

void Boss::afficher(){
	cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl;
}
