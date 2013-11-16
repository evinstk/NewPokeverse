#include "Movable.h"
#include "XStationary.h"
#include "MovingLeft.h"
#include "MovingRight.h"
#include "YStationary.h"
#include "MovingUp.h"
#include "MovingDown.h"

Movable::Movable() {
  _x_stationary = new XStationary(this);
  _moving_left = new MovingLeft(this);
  _moving_right = new MovingRight(this);

  _x_state = _x_stationary;

  _y_stationary = new YStationary(this);
  _moving_up = new MovingUp(this);
  _moving_down = new MovingDown(this);

  _y_state = _y_stationary;
}

Movable::~Movable() {
  delete _x_stationary;
  delete _moving_left;
  delete _moving_right;
  delete _y_stationary;
  delete _moving_up;
  delete _moving_down;
}

Movable::MoveState *Movable::getXStationary() const {
  return _x_stationary;
}

Movable::MoveState *Movable::getMovingLeft() const {
  return _moving_left;
}

Movable::MoveState *Movable::getMovingRight() const {
  return _moving_right;
}

void Movable::setXState(Movable::MoveState *move_state) {
  _x_state = move_state;
}

Movable::MoveState::Type Movable::getXStateType() const {
  return _x_state->getType();
}

void Movable::rightPress() {
  _x_state->posPress();
}

void Movable::leftPress() {
  _x_state->negPress();
}

void Movable::rightRelease() {
  _x_state->posRelease();
}

void Movable::leftRelease() {
  _x_state->negRelease();
}

Movable::MoveState *Movable::getYStationary() const {
  return _y_stationary;
}

Movable::MoveState *Movable::getMovingUp() const {
  return _moving_up;
}

Movable::MoveState *Movable::getMovingDown() const {
  return _moving_down;
}

void Movable::setYState(Movable::MoveState *move_state) {
  _y_state = move_state;
}

Movable::MoveState::Type Movable::getYStateType() const {
  return _y_state->getType();
}

void Movable::upPress() {
  _y_state->negPress();
}

void Movable::downPress() {
  _y_state->posPress();
}

void Movable::upRelease() {
  _y_state->negRelease();
}

void Movable::downRelease() {
  _y_state->posRelease();
}
