#ifndef X_STATIONARY_H
#define X_STATIONARY_H

#include "Movable.h"

class XStationary: public Movable::MoveState {
 public:
  XStationary(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* X_STATIONARY_H */
