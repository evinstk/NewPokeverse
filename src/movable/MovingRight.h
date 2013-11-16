#ifndef MOVING_RIGHT_H
#define MOVING_RIGHT_H

#include "Movable.h"

class MovingRight: public Movable::MoveState {
 public:
  MovingRight(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* MOVING_RIGHT_H */
