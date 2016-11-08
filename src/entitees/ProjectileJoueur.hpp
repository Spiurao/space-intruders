#pragma once

/*!
 * \file ProjectileJoueur.hpp
 * \brief Projectile tirés par le joueur
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "SDL2/SDL.h"
#include "Projectile.hpp"

/*!
 * \class ProjectileJoueur
 * \brief Classe représentant un projectile tiré par le joueur
 */

class ProjectileJoueur: public Projectile {
public:
    /*!
     * \brief Construit le projectile
     * \param x : la coordonnée x
     * \param y : la coordonnée y
     * \param rayon : le rayon de la hitbox
     * \param angle : l'angle que suivra le projectile
     * \param vitesse : la vitesse du projectile
     * \param img : pointeur vers le sprite
     * \param rend : le renderer sur lequel on va représenter l'image
     */
	ProjectileJoueur(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend);
	/*!
	 * \brief Détruit le projectile
	 */
	~ProjectileJoueur();
private:
};