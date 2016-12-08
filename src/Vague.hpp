#pragma once

/*!
 * \file Vague.hpp
 * \brief Vague permettant de gérer les ennemis durant un stage
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "SDL2/SDL.h"
#include "entitees/Ennemi.hpp"
#include "entitees/Sbire.hpp"
#include "entitees/Boss.hpp"
#include "entitees/Joueur.hpp"
#include "SpaceIntruders.hpp"
#include <vector>

/*!
 * \class Vague
 * \brief Classe représentant les vagues d'ennemis
 */
class Vague{
    public:

        /*!
         * \brief Construit une vague
         * \param nbEnnemis : le nombre d'ennemis initiaux
         * \param formation : la formation adoptée
         * \param jeu : le jeu SpaceIntruders
         */
        Vague(unsigned int nbEnnemis, int formation, SpaceIntruders *jeu);
        
        /*!
         * \brief Accesseur
         * \return le nombre d'ennemis dans la vague
         */
        int getNbEnnemis();

        /*!
         * \brief Accesseur
         * \param id : le numéro de l'ennemi dans la vague
         * \return L'ennemi à la position id du vector
         */
        Ennemi* getEnnemi(unsigned int id);

        /*!
         * \brief Supprime un ennemi du vector
         * \param id : le numéro de l'ennemi dans la vague
         */
        void deleteEnnemi(unsigned int id);
        //std::vector<Projectile*> attaquer();

        /*!
         * \brief Met à jour les positions des ennemis
         * \param delta : le temps écoulé depuis le dernier cycle
         */
        void update(float delta);

        /*!
         * \brief Affiche les ennemis
         * \param delta : le temps écoulé depuis le dernier cycle
         * \param rendu : le renderer sur lequel on affiche les ennemis
         */
        void render(float delta, SDL_Renderer *rendu);

        /*!
         * \brief Ajoute une formation d'ennemis à la vague
         * \param nbEnnemis : le nombre d'ennemis dans la nouvelle vague
         * \param formation : la formation à adopter
         */
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
        bool bossApparu = false;
};
