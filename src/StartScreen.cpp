#include "StartScreen.hpp"
#include "Niveau.hpp"
#include <iostream>

StartScreen::StartScreen(SpaceIntruders *jeu){
	jeu_ = jeu;
	SDL_SetRenderDrawColor(jeu_->getRenderer(), 255, 0, 0, 255);
}
StartScreen::~StartScreen(){

}
void StartScreen::update (float delta){

}
void StartScreen::render (float delta, SDL_Renderer *rendu){

}
void StartScreen::keysDown(std::map<double,bool> &k){

}
void StartScreen::keysHold(std::map<double,bool> &k){

}
void StartScreen::keysUp(std::map<double,bool> &k){
	if(k[SDLK_RETURN]){
		std::shared_ptr<Niveau> niv(new Niveau(jeu_));
		jeu_->setScreen(niv);
		jeu_->setInputListener(niv);
	}
}
