#pragma once

#include "Vaisseau.hpp"
#include "ProjectileJoueur.hpp"

class Ennemi : public Vaisseau {
	
    public:
        Ennemi(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
        virtual ~Ennemi();
        void recevoirDommage(int x);
        void tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend);
        bool estMort();
        
    protected:
        int hp_;
};
