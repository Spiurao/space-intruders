#pragma once

/*!
 * \file StrategyAttaqueVerticalDescendant.hpp
 * \brief Classe servant au pattern Strategy
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include "StrategyAttaque.hpp"

/*!
 * \class StrategyAttaqueVerticalDescendant
 * \brief Classe représentant la stratégie d'un sbire : tirer un projectile vers le bas
 */
class StrategyAttaqueVerticalDescendant : public StrategyAttaque {
public:
	StrategyAttaqueVerticalDescendant();
	~StrategyAttaqueVerticalDescendant();
/*!
 * \brief Renvoie un projectile descendant à vitesse constante
 * \param x : la coordonnée x du centre du cercle
 * \param y : la coordonnée y du centre du cercle
 * \param rend : le renderer sur lequel sera représenté le boss
 * \return un vector de projectiles tirés
 */
	std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend); 
};