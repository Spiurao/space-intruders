#include <iostream>

#include "StartScreen.hpp"
#include "Niveau.hpp"
#include "Niveau1.hpp"

StartScreen::StartScreen(SpaceIntruders *jeu){
	jeu_ = jeu;
	rectBg_.x = 0; rectBg_.y = 0;
	rectBg_.w = jeu->getW(); rectBg_.h = jeu->getH();
	imgBg_ = SDL_LoadBMP("assets/startScreen.bmp");
	texBg_ = SDL_CreateTextureFromSurface(jeu->getRenderer(), imgBg_);

	SDL_Rect rectBtnStart, rectBtnExit;
	rectBtnStart.x = jeu->getW()/4; rectBtnStart.y = jeu->getH()*2/3;
	rectBtnStart.w = jeu->getW()/2; rectBtnStart.h = jeu->getW()/6;
	rectBtnExit = rectBtnStart;
	rectBtnExit.y += rectBtnStart.h;
	boutonStart = new Bouton(rectBtnStart,
							 "assets/startON.bmp","assets/startOFF.bmp",
							 jeu->getRenderer());
	boutonExit = new Bouton(rectBtnExit,
							 "assets/exitON.bmp","assets/exitOFF.bmp",
							 jeu->getRenderer());

	boutonStart->trigger();
}
StartScreen::~StartScreen(){

}
void StartScreen::update (float delta){

}
void StartScreen::render (float delta, SDL_Renderer *rendu){
	SDL_RenderCopy(rendu, texBg_, 0, &rectBg_);
	boutonStart->render(delta);
	boutonExit->render(delta);
}
void StartScreen::keysDown(std::map<double,bool> &k){
	if(k[SDLK_DOWN] || k[SDLK_UP]){
		boutonStart->trigger();
		boutonExit->trigger();
	}
}
void StartScreen::keysHold(std::map<double,bool> &k){

}
void StartScreen::keysUp(std::map<double,bool> &k){
	if(k[SDLK_RETURN]){
		if(boutonStart->isSelected()){
			std::shared_ptr<Niveau1> niv(new Niveau1(jeu_));
			jeu_->setScreen(niv);
			jeu_->setInputListener(niv);
		}
		if(boutonExit->isSelected()){
			jeu_->stop();
		}
	}
}