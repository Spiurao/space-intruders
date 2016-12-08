#pragma once

/*!
 * \file EtatSerieux.hpp
 * \brief Classe servant au pattern State
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */
#include "EtatBoss.hpp"

/*!
 * \class EtatSerieux
 * \brief Classe représentant un état d'un boss
 */
class EtatSerieux : public EtatBoss {
public:
	EtatSerieux(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
	std::vector<Projectile*> attaquer(SDL_Renderer *rend);
private:
	int angle_;
};