#pragma once

#include "SDL2/SDL.h"

class Boss;

class EtatBoss {
public:
	public EtatBoss(Boss* b);
	virtual void devenirSerieux() = 0;
	virtual void devenirTresSerieux() = 0;
	virtual void devenirFurax() = 0;
private:
	Boss* b_;
}