#include "MovingPos.h"

MovingPos::MovingPos(Movable1D *movable): _movable(movable) {}

Movable1D::MoveState::Type MovingPos::getType() const {
  return MoveState::POSITIVE;
}

void MovingPos::posPress() {}

void MovingPos::negPress() {
  _movable->setState(_movable->getStationary());
}

void MovingPos::posRelease() {
  _movable->setState(_movable->getStationary());
}

void MovingPos::negRelease() {}
