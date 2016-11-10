#pragma once

/*!
 * \file Ennemi.hpp
 * \brief Ennemi du jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "Vaisseau.hpp"
#include "ProjectileJoueur.hpp"

/*!
 * \class Ennemi
 * \brief Classe représentant un ennemi
 */
class Ennemi : public Vaisseau {
	
    public:
        /*!
         * \brief Construit un ennemi
         * \param x : la coordonnée x
         * \param y : la coordonnée y
         * \param rayon : le rayon de la hitbox
         * \param img : pointeur vers le sprite
         * \param rend : le renderer sur lequel on va représenter l'image
         * \param hp : le nombre de points de vie de l'ennemi
         */
        Ennemi(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
        /*!
         * \brief Détruit l'ennemi
         */
        virtual ~Ennemi();
        /*!
         * \brief Diminue les points de vie de l'ennemi
         * \param x : le nombre de points de vie à retirer
         */
        void recevoirDommage(int x);
        /*!
         * \brief Crée un projectile
         * \param x : la coordonnée x du projectile
         * \param y : la coordonnée y du projectile
         * \param angle : l'angle vers lequel va partir le projectile
         * \param vitesse : la vitesse du projectile
         * \param rend : le renderer sur lequel on va représenter le projectile
         */
        Projectile* tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend);
        /*!
         * \brief Vérifie si l'ennemi est mort
         * \return true si l'ennemi est mort, false sinon
         */
        bool estMort();

        virtual std::vector<Projectile*> attaquer(SDL_Renderer *rend) = 0;
        
    protected:
        int hp_;
};
