#pragma once

/*!
 * \file Niveau.hpp
 * \brief Classe représentant un niveau de jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <memory>
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
		 * \param jeu : Pointeur vers la classe princpiale du jeu
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
};
