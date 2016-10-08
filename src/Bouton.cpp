#include "Bouton.hpp"

Bouton::Bouton(SDL_Rect &rect, std::string imgOn, std::string imgOff, SDL_Renderer *renderer){
    rect_ = rect;
    renderer_ = renderer;

	imgON_ = SDL_LoadBMP(imgOn.c_str());
    imgOFF_ = SDL_LoadBMP(imgOff.c_str());
	texON_ = SDL_CreateTextureFromSurface(renderer_, imgON_);
    texOFF_ = SDL_CreateTextureFromSurface(renderer_, imgOFF_);

    selected_ = false;
    tex_ = texOFF_;
}
Bouton::~Bouton(){

}
void Bouton::trigger(){
    selected_ = !selected_;
    if(selected_){
        tex_ = texON_;
    }else{
        tex_ = texOFF_;
    }
}
void Bouton::render(float delta){
    SDL_RenderCopy(renderer_, tex_, 0, &rect_);
}

bool Bouton::isSelected(){
    return selected_;
}
