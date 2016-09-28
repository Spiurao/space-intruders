#include <iostream>
#include "boss.hpp"

using namespace std;

Boss::Boss(int x, int y, int hp): Ennemi(x, y, hp)
{}

Boss::~Boss()
{}

void Boss::afficher(){
	cout << '(' << x_ << ", " << y_ << "), " << hp_ << " hp" << endl;
}
