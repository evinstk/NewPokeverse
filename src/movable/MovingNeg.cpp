#include "MovingNeg.h"

MovingNeg::MovingNeg(Movable1D *movable): _movable(movable) {}

char MovingNeg::getDirection() const {
  return -1;
}

void MovingNeg::posBump() {
  _movable->setState(_movable->getStationary());
}

void MovingNeg::negBump() {}
