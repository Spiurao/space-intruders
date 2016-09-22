#pragma once
#include "vaisseau.hpp"

class Joueur : public Vaisseau {
    
    public:
        Joueur(int x, int y, int lives);
        ~Joueur();
        void afficher();
    
    private:
        int lives_;
};
