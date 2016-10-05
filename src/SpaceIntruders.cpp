#include "SpaceIntruders.hpp"

#include <chrono>
#include <iostream>
#include <map>

#include "Niveau.hpp"
#include "StartScreen.hpp"

SpaceIntruders::SpaceIntruders(){
	delta_ = 0.0;
}
SpaceIntruders::~SpaceIntruders(){

}
int SpaceIntruders::start(){
	boucle_ = true;

	// Démarrage de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
    	std::cout << "Impossible d'initialiser la SDL: " << SDL_GetError() << std::endl;
    	return -1;
    }

    //Dimensions de la fenetre
    SDL_GetCurrentDisplayMode(0, &dm_);
	windowDim_.x = 0; windowDim_.y = 0;
	windowDim_.w = dm_.h*2/3; windowDim_.h = dm_.h*9/10;

    //Creation de la fenetre
    window_ = SDL_CreateWindow("Space Intruders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowDim_.w, windowDim_.h, SDL_WINDOW_SHOWN);

    //Creation du renderer
    render_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(render_, 50, 50, 50, 255);

    //Creation du Niveau
	std::shared_ptr<Niveau> niveau(new Niveau(this));
    setScreen(niveau);

    //Input listener
    setInputListener(niveau);

	//Inputs
    std::map <double, bool> keysDown;
	std::map <double, bool> keysHold;
	std::map <double, bool> keysUp;

	//Boucle principale
    while(boucle_){
		//Temps au debut de la boucle (pour le calcul du delta)
    	long start = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
    	//Evenements
    	SDL_Event event;
    	while (SDL_PollEvent(&event)){
    		switch(event.type){
				case SDL_WINDOWEVENT:
				    if (event.window.event == SDL_WINDOWEVENT_CLOSE){
				        stop();
				    }
				    break;
				case SDL_KEYDOWN:
					if(!keysHold[event.key.keysym.sym]){
						keysDown[event.key.keysym.sym] = true;
						input_.get()->keysDown(keysDown);
						keysDown[event.key.keysym.sym] = false;
					}
					keysHold[event.key.keysym.sym] = true;
				    break;
				case SDL_KEYUP:
				    if (event.key.keysym.sym == SDLK_ESCAPE){
				        stop();
				    }
					keysUp[event.key.keysym.sym] = true;
					input_.get()->keysUp(keysUp);
					keysUp[event.key.keysym.sym] = false;
				    keysHold[event.key.keysym.sym] = false;
				    break;
			}
    	}
		input_.get()->keysHold(keysHold);
    	//Update
    	screen_.get()->update(delta_);
    	//Rendu
    	screen_.get()->render(delta_, render_);
		SDL_RenderPresent(render_);
    	SDL_RenderClear(render_);
		//Calcul du delta
    	long stop =  (std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1));
		delta_ = (float) (stop - start)/1000;
	}
	if(!window_){
		std::cout << "Erreur de création de la fenêtre: " << SDL_GetError() << std::endl;
		return -1;
	}

 	//Arrêt de la SDL et destruction de la fenetre et du rendu
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(render_);
    SDL_Quit();
    return 0;
}

void SpaceIntruders::stop(){
	boucle_ = false;
}

SDL_Renderer* SpaceIntruders::getRenderer(){
	return render_;
}

int SpaceIntruders::getW(){
	return windowDim_.w;
}

int SpaceIntruders::getH(){
	return windowDim_.h;
}

void SpaceIntruders::setScreen(std::shared_ptr<Screen> screen){
	screen_ = screen;
}
void SpaceIntruders::setInputListener(std::shared_ptr<InputListener> input){
	input_ = input;
}
