#include "YStationary.h"

YStationary::YStationary(Movable *movable): _movable(movable) {}

Movable::MoveState::Type YStationary::getType() const {
  return STATIONARY;
}

void YStationary::posPress() {
  _movable->setYState(_movable->getMovingDown());
}

void YStationary::negPress() {
  _movable->setYState(_movable->getMovingUp());
}

void YStationary::posRelease() {
  _movable->setYState(_movable->getMovingUp());
}

void YStationary::negRelease() {
  _movable->setYState(_movable->getMovingDown());
}
