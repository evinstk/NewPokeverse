#include "Doodad.h"

std::vector<Doodad> Doodad::_prototypes;
int Doodad::_next_slot;

Doodad Doodad::findAndClone(const int& type) {
  int index = _getIndex(type);
  if (index != -1) return _prototypes[index];
  return Doodad(NO_DOODAD, 0, 0);
}

bool Doodad::addPrototype(const BuiltInType& type,
                          const unsigned char& width,
                          const unsigned char& height) {
  addPrototype((int)type, width, height);
}

bool Doodad::addPrototype(const int& type,
                          const unsigned char& width,
                          const unsigned char& height) {
  if (_getIndex(type) != -1) return false;
  Doodad doodad(type, width, height);
  _prototypes.push_back(doodad);
  _next_slot++;
  return true;
}

bool Doodad::removePrototype(const int& type) {
  int index = _getIndex(type);
  if (index == -1) return false;
  _prototypes.erase(_prototypes.begin()+index);
  return true;
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
