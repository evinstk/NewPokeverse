#include "MovingLeft.h"

MovingLeft::MovingLeft(Movable *movable): _movable(movable) {}

Movable::MoveState::Type MovingLeft::getType() const {
  return MoveState::NEGATIVE;
}

void MovingLeft::posPress() {
  _movable->setXState(_movable->getXStationary());
}

void MovingLeft::negPress() {}

void MovingLeft::posRelease() {}

void MovingLeft::negRelease() {
  _movable->setXState(_movable->getXStationary());
}
