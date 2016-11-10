#pragma once

/*!
 * \file Joueur.hpp
 * \brief Vaisseau contrôlé par le joueur
 * \author Antoine Magnin, Pierre Caillaud
 * \version 0.1
 */

#include <iostream>
#include <map>
#include "Vaisseau.hpp"
#include "ProjectileJoueur.hpp"

/*!
 * \class Joueur
 * \brief Classe représentant le joueur
 */

class Joueur : public Vaisseau {

    public:
        /*!
         * \brief Construit le joueur
         * \param x : la coordonnée x
         * \param y : la coordonnée y
         * \param rayon : le rayon de la hitbox
         * \param img : pointeur vers le sprite
         * \param rend : le renderer sur lequel on va représenter l'image
         * \param hp : le nombre de vies du joueur
         */
        Joueur(double x, double y, double rayon, SDL_Surface *img, SDL_Renderer *rend, int vies);
        /*!
         * \brief Détruit le joueur
         */
        ~Joueur();
        /*!
         * \brief Change la vitesse de déplacement du joueur
         * \param v : la nouvelle vitesse du joueur
         */
        void setVitesse(double v);
        /*!
         * \brief Retire une vie au joueur
         */
        void retirerVie();
        /*!
         * \brief Ajoute une vie au joueur
         */
        void ajouterVie();
        /*!
         * \brief Déplace le joueur
         * \param k : l'état des touches du clavier
         * \param FenetreH : la hauteur de la fenêtre de jeu
         * \param FenetreW : la largeur de la fenêtre de jeu
         */
        void deplacer(std::map<double, bool> &k, int FenetreH, int FenetreW);
        /*!
         * \brief Ralentit le joueur si la touche LShift est pressée
         * \param k : l'état des touches du clavier
         */
        void gererVitesse(std::map<double, bool> &k);
        /*!
         * \brief Fais tirer un projectile au joueur
         * \param x : la position x du projectile
         * \param y : la position y du projectile
         * \param angle : l'angle du projectile
         * \param vitesse: la vitesse du projectile
         * \param rend : le renderer où sera représenté le projectile
         */
        void tirer(double x, double y, double angle, double vitesse, SDL_Renderer *rend);
        /*!
         * \brief Appel gererProjectiles(), gererVitesse(), deplacer(), et fais tirer deux projectiles au joueur si Z est pressée
         * \param k : l'état des touches du clavier
         * \param rend : le renderer où tout est affiché
         * \param FenetreH : la hauteur de la fenêtre de jeu
         * \param FenetreW : la largeur de la fenêtre de jeu
         */
        void gererJoueur(std::map<double, bool> &k, SDL_Renderer *rend, int FenetreH, int FenetreW);
        /*!
         * \brief Fais bouger les projectiles du joueur
         */
        void gererProjectiles();
        /*!
         * \brief Méthode de débuggage, à ne pas appeler
         */
        void afficher();

    private:
        int vies_;
        double vitesse_;
        int delay_;

        //void updateRect();
};
