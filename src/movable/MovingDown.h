#ifndef MOVING_DOWN_H
#define MOVING_DOWN_H

#include "Movable.h"

class MovingDown: public Movable::MoveState {
 public:
  MovingDown(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* MOVING_DOWN_H */
