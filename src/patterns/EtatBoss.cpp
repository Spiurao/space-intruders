#include "EtatBoss.hpp"
#include "../entitees/Boss.hpp"

EtatBoss::EtatBoss(Boss *b): b_(b), delay_(0)
{}

EtatBoss::~EtatBoss()
{}