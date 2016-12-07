#pragma once

/*!
 * \file Boss.hpp
 * \brief Boss de fin de niveau
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "Ennemi.hpp"

/*!
 * \class Boss
 * \brief Classe représentant un boss
 */
class Boss : public Ennemi {
	
	public:
		/*!
		 * \brief Construit un boss
		 * \param x : la coordonnée x du boss
		 * \param y : la coordonnée y du boss
		 * \param rayon : le rayon de la hitbox du boss
		 * \param img : l'image représentant le boss
		 * \param rend : le renderer sur lequel sera représenté le boss
		 * \param hp : le nombre du points de vie du boss
		 */
		Boss(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int hp);
		/*!
		 * \brief Détruit le boss
		 */
		~Boss();
		/*!
		 * \brief Une fonction de débuggage, à ne pas utiliser
		 */
		void afficher();

	private:
		EtatBoss* etat_;

		EtatDebut* etatDebut_; 
		EtatSerieux* etatSerieux_; 
		EtatTresSerieux* etatTresSerieux_; 
		EtatFurax* etatFurax_;
};