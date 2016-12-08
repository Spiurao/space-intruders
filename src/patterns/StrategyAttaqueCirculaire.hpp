#pragma once

/*!
 * \file StrategyAttaqueCirculaire.hpp
 * \brief Classe servant au pattern Strategy
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include "StrategyAttaque.hpp"

/*!
 * \class StrategyAttaqueCirculaire
 * \brief Classe représentant la stratégie d'un sbire : tirer un cercle de projectiles
 */
class StrategyAttaqueCirculaire : public StrategyAttaque {
public:
	StrategyAttaqueCirculaire();
	~StrategyAttaqueCirculaire();

/*!
 * \brief Renvoie un cercle de projectiles
 * \param x : la coordonnée x du centre du cercle
 * \param y : la coordonnée y du centre du cercle
 * \param rend : le renderer sur lequel sera représenté le boss
 * \return un vector de projectiles tirés
 */
	std::vector<Projectile*> attaquer(int x, int y, SDL_Renderer *rend);
};