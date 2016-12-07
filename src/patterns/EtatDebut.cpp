#include "EtatDebut.hpp"

EtatDebut::EtatDebut(Boss* b): EtatBoss(b)
{}

void EtatDebut::devenirSerieux(){
	b_->changerEtatSerieux();
}

void EtatDebut::devenirTresSerieux()
{}

void EtatDebut::devenirFurax()
{}