#include "Positionable.h"

template <class T>
Positionable<T>::Positionable(const T& x, const T& y): _x(x), _y(y) {}

template <class T>
void Positionable<T>::setX(const T& x) {
  _x = x;
}

template <class T>
void Positionable<T>::setY(const T& y) {
  _y = y;
}

template <class T>
T Positionable<T>::getX() const {
  return _x;
}

template <class T>
T Positionable<T>::getY() const {
  return _y;
}

template class Positionable<unsigned int>;
