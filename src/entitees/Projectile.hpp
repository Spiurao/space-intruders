#pragma once

/*!
 * \file Projectile.hpp
 * \brief Projectile tirés par les vaisseaux
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <math.h>
#include "SDL2/SDL.h"

/*!
 * \class Projectile
 * \brief Classe représentant un projectile
 */

class Projectile {
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
	Projectile(double x, double y, double rayon, double angle, double vitesse, SDL_Surface *img, SDL_Renderer *rend);
	/*!
	 * \brief Détruit le projectile
	 */
	virtual ~Projectile();
	/*!
	 * \brief Retourne la texture du projectile
	 * \return La texture du projectile
	 */
	SDL_Texture *getTexture();
	/*!
	 * \brief Retourne le Rect du projectile
	 * \return Le rect du projectile
	 */
	SDL_Rect getRect();
	/*!
	 * \brief Retourne le rayon du projectile
	 * \return Le rayon du projectile
	 */
	double getRayon();
	/*!
	 * \brief Fais avancer le projectile selon sa vitesse et son angle
	 */
	void avancer(float delta);

    /*!
     * \brief Vérifie si le projectile est sorti
     * \param w : la largeur de la fenêtre
     * \param h : la hauteur de la fenêtre
     * \return true si le projectile est sorti, false sinon
     */
	bool estSorti(int w, int h);
protected:
	double x_, y_, rayon_, angle_, vitesse_;
	SDL_Rect rect_;
	SDL_Surface *img_;
	SDL_Texture *tex_;

	void updateRect();
};