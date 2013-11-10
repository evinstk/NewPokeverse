#include "SimpleBackgroundMap.h"

SimpleBackgroundMap::SimpleBackgroundMap(const unsigned int& width,
                                         const unsigned int& height,
                                         const Background::Type& default_type):
  _WIDTH(width),
  _HEIGHT(height),
  _SIZE(width * height) {
  _tiles = new Background::Type[_SIZE];
  for (unsigned i = 0; i < _SIZE; ++i) {
    _tiles[i] = default_type;
  }
}

SimpleBackgroundMap::~SimpleBackgroundMap() {
  delete [] _tiles;
}

Background::Type SimpleBackgroundMap::getType(const unsigned int& x,
                                              const unsigned int& y) const {
  unsigned int index = _coordsToIndex(x, y);
  return _tiles[index];
}

void SimpleBackgroundMap::setType(const Background::Type& type, const unsigned int& x,
                                  const unsigned int& y) {
  unsigned int index = _coordsToIndex(x, y);
  if (_isInRange(index)) _tiles[index] = type;
}

SimpleBackgroundMap::SBM_Iterator::SBM_Iterator(Background::Type *tiles,
                                                unsigned int map_size):
  _index(0),
  _tiles(tiles),
  _map_size(map_size) {}

bool SimpleBackgroundMap::SBM_Iterator::hasNext() {
  return ((_index < _map_size) && (_index >= 0));
}

Background::Type SimpleBackgroundMap::SBM_Iterator::next() {
  Background::Type ret = _tiles[_index];
  _index++;
  return ret;
}

BackgroundMap::Iterator *SimpleBackgroundMap::createIterator() {
  return new SBM_Iterator(_tiles, _SIZE);
}

unsigned int SimpleBackgroundMap::_coordsToIndex(const unsigned int& x,
                                                 const unsigned int& y) const {
  return ((y * _WIDTH) + x);
}

bool SimpleBackgroundMap::_isInRange(const unsigned int& index) {
  return ((index >= 0) && (index < _SIZE));
}
