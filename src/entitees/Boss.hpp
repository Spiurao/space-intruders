#pragma once

/*!
 * \file Boss.hpp
 * \brief Boss de fin de niveau
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "Ennemi.hpp"
#include "../patterns/EtatBoss.hpp"
#include "../patterns/EtatDebut.hpp"
#include "../patterns/EtatSerieux.hpp"
#include "../patterns/EtatTresSerieux.hpp"
#include "../patterns/EtatFurax.hpp"
#include "SDL2/SDL.h"

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

		std::vector<Projectile*> attaquer(SDL_Renderer *rend);

		void gererEtat();

		void changerEtatSerieux();

		void changerEtatTresSerieux();

		void changerEtatFurax();

		int getHP();

	private:
		int hpMax_;
		EtatBoss* etat_;

		EtatDebut* etatDebut_; 
		EtatSerieux* etatSerieux_; 
		EtatTresSerieux* etatTresSerieux_; 
		EtatFurax* etatFurax_;
};