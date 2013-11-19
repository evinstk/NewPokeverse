#ifndef MOVABLE_H
#define MOVABLE_H

#include "Positionable.h"

template <class T>
class Movable: public Positionable<T> {
 public:
  enum Direction {
    NEGATIVE = -1,
    STATIONARY = 0,
    POSITIVE = 1
  };
  Movable(const T& x, const T& y);

  char getDirectionX() const;
  char getDirectionY() const;
  unsigned char getSpeed() const;

  void setDirectionX(const Direction& direction);
  void setDirectionY(const Direction& direction);
  void setSpeed(const unsigned char& speed);
 private:
  char _x_direction;
  char _y_direction;
  unsigned char _speed;
};

#endif /* MOVABLE_H */
