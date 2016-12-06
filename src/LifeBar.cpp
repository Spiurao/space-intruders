#include "LifeBar.hpp"

LifeBar::LifeBar(Joueur *joueur, SpaceIntruders *jeu){
    joueur_ = joueur;
    rectFond_.x = jeu->getW()/16; rectFond_.y = jeu->getW()/16;
	rectFond_.w = jeu->getW()/3; rectFond_.h = jeu->getW()/16;
    /*rectFond_.x = 32; rectFond_.y = 32;
    rectFond_.w = 32; rectFond_.h = 32;*/
    rectVies_ = rectFond_;
    renderer_ = jeu->getRenderer();
    val_ = 1;
}
LifeBar::~LifeBar(){

}
void LifeBar::update(float delta){
    val_ = (float)joueur_->getVies()/(float)joueur_->getViesMax();
    rectVies_.w = rectFond_.w*val_;
}
void LifeBar::render(float delta){
    SDL_SetRenderDrawColor(renderer_,255,0,0,255);//ROUGE
    SDL_RenderFillRect(renderer_, &rectFond_);
    SDL_SetRenderDrawColor(renderer_,0,0,0,255);//ROUGE

    SDL_SetRenderDrawColor(renderer_,0,255,0,255);//VERT
    SDL_RenderFillRect(renderer_, &rectVies_);
}
