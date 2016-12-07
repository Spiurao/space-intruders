#include "EtatSerieux.hpp"

EtatSerieux::EtatSerieux(Boss* b): EtatBoss(b)
{}

void EtatSerieux::devenirSerieux()
{}

void EtatSerieux::devenirTresSerieux()
{
	b_->changerEtatSerieux();
}

void EtatSerieux::devenirFurax()
{}