#include <iostream>

#include "Niveau.hpp"
#include "StartScreen.hpp"

Niveau::Niveau(SpaceIntruders *jeu){
	jeu_ = jeu;
	SDL_SetRenderDrawColor(jeu->getRenderer(), 0, 0, 0, 0);
}
Niveau::~Niveau(){
	
}
void Niveau::update (float delta){

}
void Niveau::render (float delta, SDL_Renderer *rendu){

}
void Niveau::keysDown(std::map<double,bool> &k){

}
void Niveau::keysHold(std::map<double,bool> &k){

}
void Niveau::keysUp(std::map<double,bool> &k){
	if(k[SDLK_RETURN]){
		std::shared_ptr<StartScreen> ss(new StartScreen(jeu_));
		jeu_->setScreen(ss);
		jeu_->setInputListener(ss);
	}
}
