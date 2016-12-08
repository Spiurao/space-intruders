#pragma once

/*!
 * \file EtatFurax.hpp
 * \brief Classe servant au pattern State
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include "EtatBoss.hpp"

/*!
 * \class EtatFurax
 * \brief Classe représentant un état d'un boss
 */

class EtatFurax : public EtatBoss {
public:
	EtatFurax(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
private:
	int delay_;
	int angle_;
};