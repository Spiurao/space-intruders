#pragma once

/*!
 * \file Niveau1.hpp
 * \brief Niveau 1 du jeu
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <vector>
#include "SDL2/SDL.h"
#include "Niveau.hpp"
#include "entitees/Ennemi.hpp"
#include "entitees/Sbire.hpp"
#include "entitees/Joueur.hpp"
#include "StartScreen.hpp"
#include "GameOverScreen.hpp"
#include "Vague.hpp"
#include "LifeBar.hpp"


/*!
 * \class Niveau1
 * \brief Classe représentant le premier niveau
 */
class Niveau1 : public Niveau {
public:
	/*!
     * \brief Construit le niveau
     * \param jeu : Pointeur vers la classe principale du jeu
	 */
	Niveau1(SpaceIntruders *jeu);
	/*!
     * \brief Détruit le niveau
	 */
	~Niveau1();
	/*!
	 * \brief Méthode appelée a chaque boucle de jeu
	 * \param delta : Temps écoulé depuis le dernier appel
	 */
	void update(float delta);
	/*!
	 * \brief Méthode appelée a chaque boucle de jeu
	 * \param delta : Temps écoulé depuis le dernier appel
	 * \param rendu : Pointeur vers le rendu courant
	 */
	void render(float delta, SDL_Renderer *render);
	/*!
	 * \brief Méthode transmettant les infos sur les clés clavier juste pressées
	 * \param k : Clés juste pressées
	 */
	void keysDown(std::map<double,bool> &k);
	/*!
	 * \brief Méthode transmettant les infos sur les clés clavier actuellement pressées
	 * \param k : Clés actuellement pressées
	 */
	void keysHold(std::map<double,bool> &k);
	/*!
	 * \brief Méthode transmettant les infos sur les clés clavier juste relachées
	 * \param k : Clés juste relachées
	 */
	void keysUp(std::map<double,bool> &k);

private:
	Vague vague_;
	float intervalVagues_;
	float tempsVague_;
	int nbVagues_ = 0;
	int maxVague_ = 5;

	std::vector<Projectile*> vpe_;
	Joueur joueur_;
	LifeBar *lifeBar_;
	SDL_Rect rect_;
	SDL_Surface *imgBg_;
	SDL_Texture *texBg_;
};
