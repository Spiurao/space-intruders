#pragma once

/*!
 * \file GameOverScreen.hpp
 * \brief Ecran Game Over
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <memory>

#include "Screen.hpp"
#include "StartScreen.hpp"
#include "SpaceIntruders.hpp"
#include "Bouton.hpp"

/*!
  * \class
  * \brief
  */
class GameOverScreen : public Screen{
	public:
		/*!
		 * \brief Construit un écran de Game Over
		 * \param jeu : Pointeur vers la classe princpiale du jeu
		 */
		GameOverScreen(SpaceIntruders *jeu);
		/*!
		 * \brief Detruit l'écran Game Over
		 */
		~GameOverScreen();
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
};
