#include "EtatBoss.hpp"

class EtatTresSerieux : EtatBoss {
public:
	EtatTresSerieux(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
}