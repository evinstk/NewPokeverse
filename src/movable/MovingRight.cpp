#include "MovingRight.h"

MovingRight::MovingRight(Movable *movable): _movable(movable) {}

Movable::MoveState::Type MovingRight::getType() const {
  return MoveState::POSITIVE;
}

void MovingRight::posPress() {}

void MovingRight::negPress() {
  _movable->setXState(_movable->getXStationary());
}

void MovingRight::posRelease() {
  _movable->setXState(_movable->getXStationary());
}

void MovingRight::negRelease() {}
