#include "Doodad.h"

std::vector<Doodad> Doodad::_prototypes;
int Doodad::_next_slot;

Doodad::Doodad(): _type(NO_DOODAD), _w(0), _h(0) {}

Doodad Doodad::findAndClone(const int& type) {
  int index = _getIndex(type);
  if (index != -1) return _prototypes[index];
  return Doodad();
}

Doodad::Doodad(const int& type, const unsigned char& width, const unsigned char& height):
  _type(type),
  _w(width),
  _h(height) {
}

int Doodad::getType() const {
  return _type;
}

unsigned char Doodad::getWidth() const {
  return _w;
}

unsigned char Doodad::getHeight() const {
  return _h;
}

int Doodad::_getIndex(const int& type) {
  for (int i = 0; i < _next_slot; i++) {
    if (_prototypes[i].getType() == type) {
      return i;
    }
  }
  return -1;
}
