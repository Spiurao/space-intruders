#include "Vague.hpp"

Vague::Vague(unsigned int nbEnnemis, int formation, SpaceIntruders *jeu){
    nbEnnemis_ = 0;
    jeu_ = jeu;
    add(nbEnnemis, formation);
}

int Vague::getNbEnnemis(){
    return nbEnnemis_;
}

Ennemi* Vague::getEnnemi(unsigned int id){
    if(id<nbEnnemis_){
        return ennemis_[id];
    }
    return NULL;
}

void Vague::render(float delta, SDL_Renderer *rendu){
    for(auto e: ennemis_){
        SDL_Rect rectEnnemi = e->getRect();
        SDL_RenderCopy(jeu_->getRenderer(), e->getTexture(), NULL, &rectEnnemi);
    }
}

void Vague::deleteEnnemi(unsigned int id){
    if(id<nbEnnemis_){
        delete ennemis_[id];
        ennemis_.erase(ennemis_.begin()+id);
        --nbEnnemis_;
    }
}

void Vague::update(float delta){
    if(!bossApparu){
        for(unsigned int i=0; i< nbEnnemis_; ++i){
            //Mouvement
            ennemis_[i]->bouger(0,100*delta);
            //Tir
            /*ennemis_[i]->tirer(ennemis_[i]->getRect().x, ennemis_[i]->getRect().y, 0, 0.1, jeu_->getRenderer(), delta);
    		for(auto pe: ennemis_[i]->getProjectiles()){
    			pe->avancer();
            }*/
            //Sortie
            if(ennemis_[i]->estSorti(jeu_->getW(), jeu_->getH()))
                deleteEnnemi(i);
            
        }
    }
    else if(nbEnnemis_>0){
        Boss* b = dynamic_cast<Boss*>(ennemis_[0]);
        if(b)
            b->gererEtat();
    }
}

void Vague::add(unsigned int nbEnnemis, int formation){
    nbEnnemis_ += nbEnnemis;

    if(nbEnnemis>10)
        nbEnnemis=jeu_->getW()/40;

    for(unsigned int i=0; i<nbEnnemis; ++i){
        if(formation == HORIZONTALE){
            int ecart = jeu_->getW()/nbEnnemis-40;
            int startX = (jeu_->getW()-(nbEnnemis)*(40+ecart)+ecart)/2;
            ennemis_.push_back(new Sbire(startX+i*(40+ecart),
                -40, 20,
                SDL_LoadBMP("assets/sbirampon.bmp"),
                jeu_->getRenderer(), 20));
        }

        if(formation == VERTICALE){
            int ecart = 40;
            ennemis_.push_back(new Sbire(jeu_->getW()/2-20,
                -(ecart+40)*(int)i, 20,
                SDL_LoadBMP("assets/sbirampon.bmp"),
                jeu_->getRenderer(), 20));
        }

        if(formation == FLECHE){
            int x,y;
            if(i%2==0){
                x = (jeu_->getW()-40)/2-40*(i/2);
                y =((int)i/2)*-40;
            }else{
                x = (jeu_->getW()-40)/2+40*((i-1)/2)+40;
                y =((((int)i-1)/2)*-40)-40;
            }
            ennemis_.push_back(new Sbire(x,
                y, 20,
                SDL_LoadBMP("assets/sbirampon.bmp"),
                jeu_->getRenderer(), 20));
        }

        if(formation == BOSS){
            ennemis_.push_back(new Boss(jeu_->getW()/2-64,
            jeu_->getH()/5, 35, SDL_LoadBMP("assets/meka-nar.bmp"),
            jeu_->getRenderer(), 200));
            bossApparu = true;
        }
    }
}
