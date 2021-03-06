#pragma once

/*!
 * \file Niveau.hpp
 * \brief Classe représentant un niveau de jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <memory>
#include "math.h"
#include "Screen.hpp"
#include "SpaceIntruders.hpp"

/*!
  * \class Niveau
  * \brief Classe représentant un niveau de jeu
  */
class Niveau : public Screen{
	public:
		/*!
		 * \brief Construit un niveau
		 * \param jeu : Pointeur vers la classe principale du jeu
		 */
		Niveau(SpaceIntruders *jeu);
		/*!
		 * \brief Detruit un niveau
		 */
		~Niveau();
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 */
		virtual void update (float delta);
		/*!
		 * \brief Méthode appelée a chaque boucle de jeu
		 * \param delta : Temps écoulé depuis le dernier appel
		 * \param rendu : Pointeur vers le rendu courant
		 */
		virtual void render (float delta, SDL_Renderer *rendu);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier juste pressées
		 * \param k : Clés juste pressées
		 */
		virtual void keysDown(std::map<double,bool> &k);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier actuellement pressées
		 * \param k : Clés actuellement pressées
		 */
		virtual void keysHold(std::map<double,bool> &k);
		/*!
		 * \brief Méthode transmettant les infos sur les clés clavier juste relachées
		 * \param k : Clés juste relachées
		 */
		virtual void keysUp(std::map<double,bool> &k);

	protected:
		SpaceIntruders *jeu_;
};
