#pragma once

/*!
 * \file Vaisseau.hpp
 * \brief Superclasse de tous les vaisseaux
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <memory>
#include <vector>
#include "SDL2/SDL.h"
#include "Projectile.hpp"

/*!
 * \class Sbire
 * \brief Classe représentant les sbires basiques du jeu
 */

class Vaisseau {
	public:
 	    /*!
	     * \brief Construit le vaisseau
	     * \param x : la coordonnée x
	     * \param y : la coordonnée y
	     * \param rayon : le rayon de la hitbox
	     * \param img : pointeur vers le sprite
	     * \param rend : le renderer sur lequel on va représenter l'image
	     */
		Vaisseau(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend);
		/*!
		 * \brief Détruit le vaisseau
		 */
		virtual ~Vaisseau();
		/*!
		 * \brief Méthode de débuggage
		 */
		virtual void afficher() = 0;
        /*!
         * \brief Fais tirer un projectile au joueur
         * \param x : la position x du projectile
         * \param y : la position y du projectile
         * \param angle : l'angle du projectile
         * \param vitesse: la vitesse du projectile
         * \param rend : le renderer où sera représenté le projectile
         */
		virtual void tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend) = 0;
		/*!
		 * \brief Fais se déplacer le vaisseau
		 * \param x : le déplacement horizontal
		 * \param y : le déplacement vertical
		 */
		void bouger(double x, double y);
		/*!
		 * \brief Retourne la texture du vaisseau
		 * \return La texture du vaisseau
		 */
		SDL_Texture *getTexture();
		/*!
		 * \brief Retourne le rect du vaisseau
		 * \return le rect du vaisseau
		 */
		SDL_Rect getRect();
		/*!
		 * \brief Retourne le rayon de la hitbox
		 * \return le rayon de la hitbox
		 */
		double getRayon();
		/*!
		 * \brief Retourne la référence de la  liste des projectiles tirés par le vaisseau
		 * \return un vecteur de pointeurs vers Projectile
		 */
		std::vector<Projectile*>& getProjectiles();

	protected:
		double x_, y_, rayon_;
		std::vector<Projectile*> vp_;
		SDL_Rect rect_;
		SDL_Surface *img_;
		SDL_Texture *tex_;
};

