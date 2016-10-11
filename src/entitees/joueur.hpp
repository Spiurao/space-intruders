#pragma once

#include "vaisseau.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies);
        ~Joueur();
        void setVitesse(double v);
        void retirerVie();
        void ajouterVie();
        void deplacer(std::map<double, bool> &k);
        void afficher();
    
    private:
        int vies_;
        double vitesse_;
};
