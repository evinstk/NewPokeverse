#ifndef IMOVABLE_2D_H
#define IMOVABLE_2D_H

class IMovable2D {
 public:
  virtual char getDirectionX() const = 0;

  virtual void rightBump() = 0;
  virtual void leftBump() = 0;

  virtual char getDirectionY() const = 0;

  virtual void downBump() = 0;
  virtual void upBump() = 0;
};

#endif /* IMOVABLE_2D_H */
