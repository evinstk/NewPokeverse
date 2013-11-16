#ifndef MOVING_UP_H
#define MOVING_UP_H

#include "Movable.h"

class MovingUp: public Movable::MoveState {
 public:
  MovingUp(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* MOVING_UP_H */
