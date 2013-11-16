#include "MovingDown.h"

MovingDown::MovingDown(Movable *movable): _movable(movable) {}

Movable::MoveState::Type MovingDown::getType() const {
  return POSITIVE;
}

void MovingDown::posPress() {}

void MovingDown::negPress() {
  _movable->setYState(_movable->getYStationary());
}

void MovingDown::posRelease() {
  _movable->setYState(_movable->getYStationary());
}

void MovingDown::negRelease() {}
