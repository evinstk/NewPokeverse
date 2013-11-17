#include "MovingPos.h"

MovingPos::MovingPos(Movable1D *movable): _movable(movable) {}

char MovingPos::getDirection() const {
  return 1;
}

void MovingPos::posBump() {}

void MovingPos::negBump() {
  _movable->setState(_movable->getStationary());
}
