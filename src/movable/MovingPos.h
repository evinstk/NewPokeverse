#ifndef MOVING_POS_H
#define MOVING_POS_H

#include "Movable1D.h"

class MovingPos: public Movable1D::MoveState {
 public:
  MovingPos(Movable1D *movable);
  virtual char getDirection() const;
  virtual void posBump();
  virtual void negBump();
 private:
  Movable1D *_movable;
};

#endif /* MOVING_RIGHT_H */
