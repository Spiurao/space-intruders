#pragma once
#include "vaisseau.hpp"

class Ennemi : public Vaisseau {
	
    public:
        Ennemi(int x, int y, int hp);
        ~Ennemi();
        void afficher();
        void recevoirDommage(int x);
        
    private:
        unsigned hp_;
};
