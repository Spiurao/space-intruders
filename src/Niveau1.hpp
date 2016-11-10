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
#include "Vague.hpp"


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
<<<<<<< HEAD
	//std::vector<Ennemi*> ennemis_;
	Vague vague_;
	float intervalVagues_;
	float tempsVague_;
=======
	int delay = 0;
	std::vector<Ennemi*> ennemis_;
	std::vector<Projectile*> vpe_;
>>>>>>> 589b165e9a81aaa7645f7ccdca09b71ef6ded5ba
	Joueur joueur_;
};
