#include "Stationary.h"

Stationary::Stationary(Movable1D *movable): _movable(movable) {}

Movable1D::MoveState::Type Stationary::getType() const {
  return STATIONARY;
}

void Stationary::posPress() {
  _movable->setState(_movable->getMovingPos());
}

void Stationary::negPress() {
  _movable->setState(_movable->getMovingNeg());
}

void Stationary::posRelease() {
  _movable->setState(_movable->getMovingNeg());
}

void Stationary::negRelease() {
  _movable->setState(_movable->getMovingPos());
}