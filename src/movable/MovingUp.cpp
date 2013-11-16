#include "MovingUp.h"

MovingUp::MovingUp(Movable *movable): _movable(movable) {}

Movable::MoveState::Type MovingUp::getType() const {
  return NEGATIVE;
}

void MovingUp::posPress() {
  _movable->setYState(_movable->getYStationary());
}

void MovingUp::negPress() {}

void MovingUp::posRelease() {}

void MovingUp::negRelease() {
  _movable->setYState(_movable->getYStationary());
}
