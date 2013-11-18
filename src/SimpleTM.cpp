#include "SimpleTM.h"
#include "util/CoordConverter.h"
#include "Background.h"

SimpleTM::SimpleTM(const unsigned int& width, const unsigned int& height, const int& default_type):
  _WIDTH(width),
  _HEIGHT(height),
  _SIZE(width * height) {
  _tiles = new int[_SIZE];
  for (unsigned i = 0; i < _SIZE; ++i) {
    _tiles[i] = default_type;
  }
}

SimpleTM::~SimpleTM() {
  delete [] _tiles;
}

int SimpleTM::getType(const unsigned int& x, const unsigned int& y) const {
  unsigned int index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index)) return _tiles[index];
  return Background::NO_BACKGROUND;
}

void SimpleTM::setType(const int& type,
                                  const unsigned int& x, const unsigned int& y) {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  _tiles[index] = type;
}

unsigned int SimpleTM::getWidth() const {
  return _WIDTH;
}

unsigned int SimpleTM::getHeight() const {
  return _HEIGHT;
}

unsigned long SimpleTM::getSize() const {
  return _SIZE;
}

bool SimpleTM::_isInRange(const unsigned int& index) const {
  return ((index >= 0) && (index < _SIZE));
}
