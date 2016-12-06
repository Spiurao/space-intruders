#pragma once

/*!
 * \file LifeBar.hpp
 * \brief Construit un barre de vie
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include "entitees/Joueur.hpp"
#include "SpaceIntruders.hpp"

/*!
  * \class barre de vie
  * \brief Classe representant une barre de vie
  */
class LifeBar{
    public:
        /*!
		 * \brief Construit une barre de vie
		 * \param rect : Dimensions et position de la barre de vie
         * \param Joueur : Joueur dont la vie doit etre affchée
         * \param renderer : Renderer sur lequel afficher la barre de vie
		 */
        LifeBar(Joueur *joueur, SpaceIntruders *jeu);
        /*!
         * \brief Detruit un barre de vie
         */
        ~LifeBar();
        /*!
         * \brief Met à jour la barre de vie
         * \param delta : Temps écoulé depuis le dernier appel
         */
        void update(float delta);
        /*!
         * \brief Rendu de la barre de vie
         * \param delta : Temps écoulé depuis le dernier appel
         */
        void render(float delta);

    private:
        SDL_Renderer *renderer_;
        Joueur *joueur_;
		SDL_Rect rectFond_, rectVies_;
        float val_;

};
