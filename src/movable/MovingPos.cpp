#include "MovingPos.h"

MovingPos::MovingPos(Movable1D *movable): _movable(movable) {}

char MovingPos::getDirection() const {
  return 1;
}

void MovingPos::posPress() {}

void MovingPos::negPress() {
  _movable->setState(_movable->getStationary());
}

void MovingPos::posRelease() {
  _movable->setState(_movable->getStationary());
}

void MovingPos::negRelease() {}
