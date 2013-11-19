#ifndef POSITIONABLE_H
#define POSITIONABLE_H

template <class T>
class Positionable {
public:
  Positionable(const T& x = 0, const T& y = 0);

  virtual void setX(const T& x);
  virtual void setY(const T& y);

  virtual T getX() const;
  virtual T getY() const;
 private:
  T _x;
  T _y;
};

#endif /* POSITIONABLE_H */
