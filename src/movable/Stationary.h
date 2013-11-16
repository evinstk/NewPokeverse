#ifndef STATIONARY_H
#define STATIONARY_H

#include "Movable1D.h"

class Stationary: public Movable1D::MoveState {
 public:
  Stationary(Movable1D *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable1D *_movable;
};

#endif /* STATIONARY_H */
