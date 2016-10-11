#pragma once

/*!
 * \file Screen.hpp
 * \brief Classe représenatnt un écran de jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <iostream>
#include "InputListener.hpp"

/*!
  * \interface Screen
  * \brief Classe representant un écran de jeu
  */
class Screen : public InputListener{
	public:
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 */
		virtual void update(float delta) = 0;
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 * \param rendu : Pointeur vers le rendu courant
		 */
		virtual void render (float delta, SDL_Renderer *rendu) = 0;
		/*!
		 * \brief Méthodes transmettant les infos sur les clés clavier juste pressées
		 * \param k : Clés juste pressées
		 */
		virtual void keysDown(std::map<double,bool> &k) = 0;
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier actuellement pressées
		 * \param k : Clés actuellement pressées
		 */
		virtual void keysHold(std::map<double,bool> &k) = 0;
		/*!
		 * \brief Méthodes transmettant les infos sur les clés clavier juste relachées
		 * \param k : Clés juste relachées
		 */
		virtual void keysUp(std::map<double,bool> &k) = 0;
};
