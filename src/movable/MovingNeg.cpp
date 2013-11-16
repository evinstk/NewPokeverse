#include "MovingNeg.h"

MovingNeg::MovingNeg(Movable1D *movable): _movable(movable) {}

Movable1D::MoveState::Type MovingNeg::getType() const {
  return MoveState::NEGATIVE;
}

void MovingNeg::posPress() {
  _movable->setState(_movable->getStationary());
}

void MovingNeg::negPress() {}

void MovingNeg::posRelease() {}

void MovingNeg::negRelease() {
  _movable->setState(_movable->getStationary());
}
