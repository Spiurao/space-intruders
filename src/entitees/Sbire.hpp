#pragma once

/*!
 * \file Sbire.hpp
 * \brief Sbire de base du jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <iostream>
#include "Ennemi.hpp"
#include "../patterns/StrategyAttaque.hpp"
#include "../patterns/StrategyAttaqueCirculaire.hpp"
#include "../patterns/StrategyAttaqueVerticalDescendant.hpp"

/*!
 * \class Sbire
 * \brief Classe représentant les sbires basiques du jeu
 */

class Sbire : public Ennemi {
	
	public:
 	    /*!
	     * \brief Construit le sbire
	     * \param x : la coordonnée x
	     * \param y : la coordonnée y
	     * \param rayon : le rayon de la hitbox
	     * \param img : pointeur vers le sprite
	     * \param rend : le renderer sur lequel on va représenter l'image
	     * \param hp : le nombre de points de vie du sbire
	     */
		Sbire(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
		/*!
		 * \brief Détruit le sbire
		 */
		~Sbire();
		/*!
		 * \brief Fonction de débuggage, ne pas utiliser
		 */
		void afficher();

		std::vector<Projectile*> attaquer(SDL_Renderer *rend);
	private:
		int delay_;
		StrategyAttaque *attaque_;
};
