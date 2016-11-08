#pragma once

#include <iostream>
#include <map>
#include "Vaisseau.hpp"
#include "ProjectileJoueur.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies);
        ~Joueur();
        void setVitesse(double v);
        void retirerVie();
        void ajouterVie();
        void deplacer(std::map<double, bool> &k, int FenetreH, int FenetreW);
        void gererVitesse(std::map<double, bool> &k);
        void tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend);
        void gererJoueur(std::map<double, bool> &k, SDL_Renderer *rend, int FenetreH, int FenetreW);
        void gererProjectiles();
        void afficher();
    
    private:
        int vies_;
        double vitesse_;
        int delay_;

        void updateRect();
};
