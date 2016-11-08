#pragma once

#include "Vaisseau.hpp"

class Ennemi : public Vaisseau {
	
    public:
        Ennemi(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
        virtual ~Ennemi();
        void recevoirDommage(int x);
        bool estMort();
        
    protected:
        int hp_;
};
