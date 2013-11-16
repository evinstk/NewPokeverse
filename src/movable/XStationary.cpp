#include "XStationary.h"

XStationary::XStationary(Movable *movable): _movable(movable) {}

Movable::MoveState::Type XStationary::getType() const {
  return STATIONARY;
}

void XStationary::posPress() {
  _movable->setXState(_movable->getMovingRight());
}

void XStationary::negPress() {
  _movable->setXState(_movable->getMovingLeft());
}

void XStationary::posRelease() {
  _movable->setXState(_movable->getMovingLeft());
}

void XStationary::negRelease() {
  _movable->setXState(_movable->getMovingRight());
}
