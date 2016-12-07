#include "EtatBoss.hpp"

class EtatDebut : EtatBoss {
public:
	EtatDebut(Boss* b);
	void devenirSerieux();
	void devenirTresSerieux();
	void devenirFurax();
}