#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Vaisseau.hpp"
#include "Projectile.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies);
        ~Joueur();
        void setVitesse(double v);
        void retirerVie();
        void ajouterVie();
        void deplacer(std::map<double, bool> &k, int FenetreH, int FenetreW);
        void gererVitesse(std::map<double, bool> &k);
        void tirer(SDL_Renderer *rend);
        void gererJoueur(std::map<double, bool> &k, SDL_Renderer *rend, int FenetreH, int FenetreW);
        std::vector<Projectile*>& getProjectiles();
        void gererProjectiles();
        void afficher();
    
    private:
        int vies_;
        double vitesse_;
        std::vector<Projectile*> vp_;
        int delay_;

        void updateRect();
};
