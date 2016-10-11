#pragma once

#include <vector>
#include "SDL2/SDL.h"
#include "niveau.hpp"

class Niveau1 : public Niveau {
public:
	Niveau1(SpaceIntruders *jeu);
	~Niveau1();
	void keysDown(std::map<double,bool> &k);
	void keysHold(std::map<double,bool> &k);
	void keysUp(std::map<double,bool> &k);
private:
	std::vector<Ennemi> ennemis_;
	Joueur joueur_;
}