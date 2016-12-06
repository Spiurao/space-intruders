#pragma once

/*!
 * \file Bouton.hpp
 * \brief Construit un bouton
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <SDL2/SDL.h>
#include "Screen.hpp"

/*!
  * \class Bouton
  * \brief Classe representant un bouton
  */
class Bouton{
    public:
        /*!
		 * \brief Construit un bouton
		 * \param rect : Dimensions et position du bouton
         * \param imgOn : Chemin vers l'image du bouton "allumé"
         * \param imgOff : Chemin vers l'image du bouton "éteint"
         * \param renderer : Renderer sur lequel afficher le bouton
		 */
        Bouton(SDL_Rect &rect, std::string imgOn, std::string imgOff, SDL_Renderer *renderer);
        /*!
         * \brief Detruit un bouton
         */
        ~Bouton();
        /*!
         * \brief Selectionne le bouton s'il ne l'est pas, et inversement
         */
        void trigger();
        /*!
         * \brief Rendu du bouton
         * \param delta : Temps écoulé depuis le dernier appel
         */
        void render(float delta);
        /*!
         * \brief Indique si les bouton est sélectionné ou pas
         * \return Vrai si le bouton est sélectionné
         */
        bool isSelected();

    private:
        bool selected_;

        SDL_Renderer *renderer_;

        SDL_Surface *imgON_, *imgOFF_;
		SDL_Texture *texON_, *texOFF_, *tex_;
		SDL_Rect rect_;
};
