#pragma once

#include "vaisseau.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies);
        ~Joueur();
        void retirerVie();
        void ajouterVie();
        void afficher();
    
    private:
        int vies_;
};
