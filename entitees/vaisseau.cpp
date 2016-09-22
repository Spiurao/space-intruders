#include <iostream>
#include "vaisseau.hpp"

using namespace std;

Vaisseau::Vaisseau(int x, int y) : x_(x), y_(y)
{}

Vaisseau::~Vaisseau(){}

void Vaisseau::afficher(){
    cout << '(' << x_ << ", " << y_ << ')' << endl;
}

void Vaisseau::bouger(int x, int y){
    x_+=x;
    y_+=y;
}
