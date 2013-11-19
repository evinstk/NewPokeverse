#ifndef MOVABLE_2D_H
#define MOVABLE_2D_H

#include "IMovable2D.h"
#include "Movable1D.h"

class Movable2D: public IMovable2D {
 public:
  Movable2D();
  ~Movable2D();

  char getDirectionX() const;

  void rightBump();
  void leftBump();

  char getDirectionY() const;

  void downBump();
  void upBump();
 private:
  Movable1D *_x_dimension;
  Movable1D *_y_dimension;
};

#endif /* MOVABLE_2D_H */
