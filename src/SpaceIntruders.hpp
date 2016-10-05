#pragma once

/*!
 * \file SpaceIntruders.hpp
 * \brief Classe principale du jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <memory>
#include "Screen.hpp"
#include "InputListener.hpp"

/*!
 * \class SpaceIntruders
 * \brief Classe representant le jeu
 */
class SpaceIntruders{
	public:
		/*!
     	 * \brief Construit la classe SpaceIntruders
		 */
		SpaceIntruders();
		/*!
		 * \brief Detruit la classe SpaceIntruders
		 */
		~SpaceIntruders();
		/*!
		 * \brief A utiliser pour lancer le jeu
		 */
		int start();
		/*!
		 * \brief A utiliser pour stopper le jeu
		 */
		void stop();
		/*!
		 * \brief Definit l'ecran courant du jeu
		 * \param screen : Ecran à afficher
		 */
		void setScreen(std::shared_ptr<Screen> screen);
		/*!
		 * \brief Definit la classe gérant les entrées
		 * \param input : Classe gérant les entrées
		 */
		void setInputListener(std::shared_ptr<InputListener> input);
		/*!
		 * \brief Accesseur du rendu
		 * \return Renderer du jeu
		 */
		SDL_Renderer* getRenderer();
		/*!
		 * \brief Accesseur de la largeur de la fenêtre
		 * \return Largeur de la fenêtre
		 */
		int getW();
		/*!
		 * \brief Accesseur de la hauteur de la fenêtre
		 * \return Hauteur de la fenêtre
		 */
		int getH();
	private:
		bool boucle_;
		float delta_;
		SDL_Window* window_;
		SDL_Renderer *render_;
		std::shared_ptr<Screen> screen_;
		std::shared_ptr<InputListener> input_;
		SDL_DisplayMode dm_;
		SDL_Rect windowDim_;
};
