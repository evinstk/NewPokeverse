#ifndef Y_STATIONARY_H
#define Y_STATIONARY_H

#include "Movable.h"

class YStationary: public Movable::MoveState {
 public:
  YStationary(Movable *movable);
  virtual Type getType() const;
  virtual void posPress();
  virtual void negPress();
  virtual void posRelease();
  virtual void negRelease();
 private:
  Movable *_movable;
};

#endif /* Y_STATIONARY_H */
