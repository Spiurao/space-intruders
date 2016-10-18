#pragma once

#include "Vaisseau.hpp"

class Ennemi : public Vaisseau {
	
    public:
        Ennemi(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
        ~Ennemi();
        void recevoirDommage(int x);
        
    protected:
        int hp_;
};
