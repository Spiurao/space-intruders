#pragma once

/*!
 * \file EtatBoss.hpp
 * \brief Classe abstraite servant au pattern State
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include "SDL2/SDL.h"
#include "../entitees/ProjectileJoueur.hpp"
#include <vector>

//forward declaration pour éviter la double inclusion
class Boss;

/*!
 * \class EtatBoss
 * \brief Classe représentant l'état d'un boss
 */
class EtatBoss {
public:

	/*!
	 * \brief Construit l'état du boss
	 * \param b : le boss dont on représente l'état
	 */
	EtatBoss(Boss* b);
	virtual ~EtatBoss();

    /*!
     * \brief Change l'état du boss
     */
	virtual void devenirSerieux() = 0;

    /*!
     * \brief Change l'état du boss
     */
	virtual void devenirTresSerieux() = 0;

    /*!
     * \brief Change l'état du boss
     */
	virtual void devenirFurax() = 0;

    /*!
     * \brief Fais attaquer l'ennemi avec une attaque variant selon l'état
     * \param rend : le renderer sur lequel seront représentés les projectiles
     * \return un vector de projectiles tirés
     */
	virtual std::vector<Projectile*> attaquer(SDL_Renderer *rend) = 0;
protected:
	Boss* b_;
	int delay_;
};