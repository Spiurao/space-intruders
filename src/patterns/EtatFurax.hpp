#include "EtatBoss.hpp"

class EtatFurax : EtatBoss {
public:
	EtatFurax(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
}