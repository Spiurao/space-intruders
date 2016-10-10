#include <iostream>
#include "vaisseau.hpp"
#include "joueur.hpp"
#include "ennemi.hpp"
#include "sbire.hpp"
#include "boss.hpp"

int main(){

	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	
	int w = dm.h*9/10;
	int h = dm.h*2/3;

	SDL_Window* fenetre;
	fenetre = SDL_CreateWindow("Space Intruders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

	SDL_Renderer *rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

	// Démarrage de la SDL
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		std::cout << "Impossible d'initialiser la SDL: " << SDL_GetError() << std::endl;
		return -1;
	}


	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);


	Joueur j{10.0, 10.0, 5.0, SDL_LoadBMP("assets/vaisseau.bmp"), rendu, 5};
	j.afficher();
	j.bouger(-2.0,55.0);
	j.afficher();
	j.retirerVie();
	j.afficher();
	j.ajouterVie();
	j.afficher();
	SDL_RenderPresent(rendu);
	SDL_Delay(3000);
	SDL_DestroyWindow(fenetre);
	SDL_DestroyRenderer(rendu);
	/*
	Sbire s{20,20,50};
	s.afficher();
	s.bouger(12,5);
	s.recevoirDommage(20);
	s.afficher();
	s.recevoirDommage(40);
	s.afficher();
	
	Boss b{10,10,250};
	b.afficher();
	b.bouger(5,-5);
	b.recevoirDommage(50);
	b.afficher();*/
}
