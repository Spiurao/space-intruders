#include <iostream>

#include "GameOverScreen.hpp"

GameOverScreen::GameOverScreen(SpaceIntruders *jeu){
	jeu_ = jeu;
	rectBg_.x = 0; rectBg_.y = 0;
	rectBg_.w = jeu->getW(); rectBg_.h = jeu->getH();
	imgBg_ = SDL_LoadBMP("assets/gameOverScreen.bmp");
	texBg_ = SDL_CreateTextureFromSurface(jeu->getRenderer(), imgBg_);
}
GameOverScreen::~GameOverScreen(){

}
void GameOverScreen::update (float delta){

}
void GameOverScreen::render (float delta, SDL_Renderer *rendu){
	SDL_RenderCopy(rendu, texBg_, 0, &rectBg_);
}
void GameOverScreen::keysDown(std::map<double,bool> &k){

}
void GameOverScreen::keysHold(std::map<double,bool> &k){

}
void GameOverScreen::keysUp(std::map<double,bool> &k){
	std::shared_ptr<StartScreen> startScreen(new StartScreen(jeu_));
	jeu_->setScreen(startScreen);
	jeu_->setInputListener(startScreen);
}
