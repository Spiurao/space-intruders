#pragma once

/*!
 * \file StartScreen.hpp
 * \brief Ecran d'accueil
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <memory>
#include "Screen.hpp"
#include "SpaceIntruders.hpp"
#include "Bouton.hpp"

/*!
  * \class
  * \brief
  */
class StartScreen : public Screen{
	public:
		/*!
		 * \brief Construit un écran d'accueil
		 * \param jeu : Pointeur vers la classe princpiale du jeu
		 */
		StartScreen(SpaceIntruders *jeu);
		/*!
		 * \brief Detruit un écran d'accueil
		 */
		~StartScreen();
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 */
		void update (float delta);
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 * \param rendu : Pointeur vers le rendu courant
		 */
		void render (float delta, SDL_Renderer *rendu);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier juste pressées
		 * \param k : Clés juste pressées
		 */
		void keysDown(std::map<double,bool> &k);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier actuellement pressées
		 * \param k : Clés actuellement pressées
		 */
		void keysHold(std::map<double,bool> &k);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier juste relachées
		 * \param k : Clés juste relachée
		 */
		void keysUp(std::map<double,bool> &k);

	private:
		SpaceIntruders *jeu_;

		SDL_Surface *imgBg_;
		SDL_Texture *texBg_;
		SDL_Rect rectBg_;

		Bouton *boutonStart, *boutonExit;

};
