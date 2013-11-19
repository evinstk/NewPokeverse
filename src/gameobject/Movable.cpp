#include "Movable.h"

template <class T>
Movable<T>::Movable(const T& x, const T& y):
  Positionable<T>(x, y), _x_direction(0), _y_direction(0), _speed(1) {}

template <class T>
char Movable<T>::getDirectionX() const {
  return _x_direction;
}

template <class T>
char Movable<T>::getDirectionY() const {
  return _y_direction;
}

template <class T>
unsigned char Movable<T>::getSpeed() const {
  return _speed;
}

template <class T>
void Movable<T>::setDirectionX(const Direction& direction) {
  _x_direction = direction;
}

template <class T>
void Movable<T>::setDirectionY(const Direction& direction) {
  _y_direction = direction;
}

template <class T>
void Movable<T>::setSpeed(const unsigned char& speed) {
  _speed = speed;
}

template class Movable<unsigned int>;
