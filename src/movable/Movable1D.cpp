#include "Movable1D.h"
#include "Stationary.h"
#include "MovingPos.h"
#include "MovingNeg.h"

Movable1D::Movable1D() {
  _stationary = new Stationary(this);
  _moving_neg = new MovingNeg(this);
  _moving_pos = new MovingPos(this);

  _state = _stationary;
}

Movable1D::~Movable1D() {
  delete _stationary;
  delete _moving_neg;
  delete _moving_pos;
}

Movable1D::MoveState *Movable1D::getStationary() const {
  return _stationary;
}

Movable1D::MoveState *Movable1D::getMovingNeg() const {
  return _moving_neg;
}

Movable1D::MoveState *Movable1D::getMovingPos() const {
  return _moving_pos;
}

void Movable1D::setState(Movable1D::MoveState *move_state) {
  _state = move_state;
}

char Movable1D::getDirection() const {
  return _state->getDirection();
}

void Movable1D::posBump() {
  _state->posBump();
}

void Movable1D::negBump() {
  _state->negBump();
}
