#ifndef MOVING_LEFT_H
#define MOVING_LEFT_H

#include "Movable.h"

class MovingLeft: public Movable::MoveState {
 public:
  MovingLeft(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* MOVING_LEFT_H */
