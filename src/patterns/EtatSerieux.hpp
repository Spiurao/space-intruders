#include "EtatBoss.hpp"

class EtatSerieux : EtatBoss {
public:
	EtatSerieux(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
}