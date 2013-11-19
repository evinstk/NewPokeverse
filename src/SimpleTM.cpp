#include "SimpleTM.h"
#include "util/CoordConverter.h"
#include "Background.h"

SimpleTM::SimpleTM(const unsigned int& width, const unsigned int& height, const unsigned& default_type):
  _WIDTH(width),
  _HEIGHT(height),
  _SIZE(width * height) {
  _tiles = new Terrain[_SIZE];
  for (unsigned i = 0; i < _SIZE; ++i) {
    _tiles[i] = Terrain(default_type);
  }
}

SimpleTM::~SimpleTM() {
  delete [] _tiles;
}

unsigned SimpleTM::getType(const unsigned int& x, const unsigned int& y) const {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index)) return _tiles[index].getType();
  return 0;
}

void SimpleTM::setType(const unsigned& type, const unsigned int& x, const unsigned int& y) {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index)) _tiles[index].setType(type);
}

bool SimpleTM::isWalkable(const unsigned int& x, const unsigned int& y) const {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  //If the terrain isn't walkable, then it isn't walkable
  if (!_tiles[index].isWalkable()) return false;

  return _allAdjacentsEqualOrHigher(x, y);
}

char SimpleTM::getElevation(const unsigned int& x, const unsigned int& y) const {
  char ret = 0;
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index)) ret = _tiles[index].getElevation();
  return ret;
}

char SimpleTM::increaseElevation(const unsigned int& x, const unsigned int& y) {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index) && _allAdjacentsEqualOrHigher(x,y))
    return _tiles[index].increaseElevation();
  return _tiles[index].getElevation();
}

char SimpleTM::decreaseElevation(const unsigned int& x, const unsigned int& y) {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index) && _allAdjacentsEqualOrLower(x,y))
    return _tiles[index].decreaseElevation();
  return _tiles[index].getElevation();
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

bool SimpleTM::_isInRange(const unsigned long& index) const {
  return ((index >= 0) && (index < _SIZE));
}

bool SimpleTM::_allAdjacentsEqualOrHigher(const unsigned int& x, const unsigned int& y) const {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  unsigned long adjacentIndex = 0;
  long iter_x = x, iter_y = y;
  for (long y_adjacent = y - 1; y_adjacent < iter_y + 2; y_adjacent++) {
    for (long x_adjacent = x - 1; x_adjacent < iter_x + 2; x_adjacent++) {
      adjacentIndex = CoordConverter::coordsToIndex(x_adjacent, y_adjacent, _WIDTH);
      if (_isInRange(adjacentIndex)) {
	if (_tiles[adjacentIndex].getElevation() < _tiles[index].getElevation()) {
	  return false;
	}
      }
    }
  }
  return true;
}

bool SimpleTM::_allAdjacentsEqualOrLower(const unsigned int& x, const unsigned int& y) const {
  unsigned long index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  unsigned long adjacentIndex = 0;
  long iter_x = x, iter_y = y;
  for (long y_adjacent = y - 1; y_adjacent < iter_y + 2; y_adjacent++) {
    for (long x_adjacent = x - 1; x_adjacent < iter_x + 2; x_adjacent++) {
      adjacentIndex = CoordConverter::coordsToIndex(x_adjacent, y_adjacent, _WIDTH);
      if (_isInRange(adjacentIndex)) {
	if (_tiles[adjacentIndex].getElevation() > _tiles[index].getElevation()) {
	  return false;
	}
      }
    }
  }
  return true;
}
