#include "Movable2D.h"

Movable2D::Movable2D() {
  _x_dimension = new Movable1D();
  _y_dimension = new Movable1D();
}

Movable2D::~Movable2D() {
  delete _x_dimension;
  delete _y_dimension;
}

char Movable2D::getDirectionX() const {
  return _x_dimension->getDirection();
}

void Movable2D::rightBump() {
  _x_dimension->posBump();
}

void Movable2D::leftBump() {
  _x_dimension->negBump();
}

char Movable2D::getDirectionY() const {
  return _y_dimension->getDirection();
}

void Movable2D::downBump() {
  _y_dimension->posBump();
}

void Movable2D::upBump() {
  _y_dimension->negBump();
}
