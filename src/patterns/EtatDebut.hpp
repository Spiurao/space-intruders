#pragma once

/*!
 * \file EtatDebut.hpp
 * \brief Classe servant au pattern State
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include "EtatBoss.hpp"

/*!
 * \class EtatDebut
 * \brief Classe représentant un état d'un boss
 */
class EtatDebut : public EtatBoss {
public:
	EtatDebut(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
};