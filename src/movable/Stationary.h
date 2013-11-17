#ifndef STATIONARY_H
#define STATIONARY_H

#include "Movable1D.h"

class Stationary: public Movable1D::MoveState {
 public:
  Stationary(Movable1D *movable);
  virtual char getDirection() const;
  virtual void posBump();
  virtual void negBump();
 private:
  Movable1D *_movable;
};

#endif /* STATIONARY_H */
