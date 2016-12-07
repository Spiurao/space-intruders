#include "EtatTresSerieux.hpp"

EtatTresSerieux::EtatTresSerieux(Boss* b): EtatBoss(b)
{}

void EtatTresSerieux::devenirSerieux()
{}

void EtatTresSerieux::devenirTresSerieux()
{}

void EtatTresSerieux::devenirFurax()
{
	b_->changerEtatSerieux();
}