#pragma once
#include "vaisseau.hpp"

class Ennemi : public Vaisseau {
	
    public:
        Ennemi(int x, int y, int hp);
        ~Ennemi();
        void recevoirDommage(int x);
        
    protected:
        int hp_;
};
