#pragma once
#include "vaisseau.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(int x, int y, int lives);
        ~Joueur();
        void retirerVie();
        void ajouterVie();
        void afficher();
    
    private:
        int lives_;
};
