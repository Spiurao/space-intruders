#pragma once

#include "SDL2/SDL.h"
#include "entitees/Ennemi.hpp"
#include "entitees/Sbire.hpp"
#include "entitees/Joueur.hpp"
#include "SpaceIntruders.hpp"
#include <vector>

class Vague{
    public:
        Vague(unsigned int nbEnnemis, int formation, SpaceIntruders *jeu);
        int getNbEnnemis();
        Ennemi* getEnnemi(unsigned int id);
        void deleteEnnemi(unsigned int id);
        //std::vector<Projectile*> attaquer();
        void update(float delta);
        void render(float delta, SDL_Renderer *rendu);
        void add(unsigned int nbEnnemis, int formation);
        //Formations
        static const int HORIZONTALE = 0;
        static const int VERTICALE = 1;
        static const int FLECHE = 2;
        static const int BOSS = 3;
    private:
        SpaceIntruders *jeu_;
        std::vector<Ennemi*> ennemis_;
        unsigned int nbEnnemis_;
};
