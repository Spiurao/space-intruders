#pragma once

/*!
 * \file InputListener.hpp
 * \brief Classe gérant les entrées
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include <map>

/*!
  * \interface InputListener
  * \brief Classe gérant les entrées
  */
class InputListener{
	public:
		//virtual ~InputListener(){}
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
		 * \param k : Clés juste relachée
		 */
		virtual void keysUp(std::map<double,bool> &k) = 0;
};
