#include "Stationary.h"

Stationary::Stationary(Movable1D *movable): _movable(movable) {}

char Stationary::getDirection() const {
  return 0;
}

void Stationary::posBump() {
  _movable->setState(_movable->getMovingPos());
}

void Stationary::negBump() {
  _movable->setState(_movable->getMovingNeg());
}
