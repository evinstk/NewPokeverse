#include "MovingNeg.h"

MovingNeg::MovingNeg(Movable1D *movable): _movable(movable) {}

char MovingNeg::getDirection() const {
  return -1;
}

void MovingNeg::posPress() {
  _movable->setState(_movable->getStationary());
}

void MovingNeg::negPress() {}

void MovingNeg::posRelease() {}

void MovingNeg::negRelease() {
  _movable->setState(_movable->getStationary());
}
