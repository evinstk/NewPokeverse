#ifndef MOVING_NEG_H
#define MOVING_NEG_H

#include "Movable1D.h"

class MovingNeg: public Movable1D::MoveState {
 public:
  MovingNeg(Movable1D *movable);
  virtual char getDirection() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable1D *_movable;
};

#endif /* MOVING_LEFT_H */
