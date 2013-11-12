#include "SimpleBackgroundMap.h"
#include "util/CoordConverter.h"

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
  unsigned int index = CoordConverter::coordsToIndex(x, y, _WIDTH);
  if (_isInRange(index)) return _tiles[index];
  return Background::NO_BACKGROUND;
}

void SimpleBackgroundMap::setType(const Background::Type& type,
                                  const unsigned int& x, const unsigned int& y,
                                  const unsigned int& w, const unsigned int& h) {
  unsigned int mx = x, my = y, mw = w, mh = h;
  _shrinkToFit(mx, my, mw, mh);
  for (SBM_Iterator it(this, mx, my, mw, mh); it.hasNext();) {
    Background::Type *ref_type = it.next();
    *ref_type = type;
  }
  //unsigned int index = _coordsToIndex(x, y);
  //if (_isInRange(index)) _tiles[index] = type;
}

unsigned int SimpleBackgroundMap::getWidth() const {
  return _WIDTH;
}

unsigned int SimpleBackgroundMap::getHeight() const {
  return _HEIGHT;
}

unsigned int SimpleBackgroundMap::getSize() const {
  return _SIZE;
}

SimpleBackgroundMap::SBM_Iterator::SBM_Iterator(SimpleBackgroundMap *map,
						const unsigned int& x,
						const unsigned int& y,
						const unsigned int& w,
						const unsigned int& h):
  _index_x(x), _index_y(y), _map(map), _x(x), _y(y), _w(w), _h(h) {}

bool SimpleBackgroundMap::SBM_Iterator::hasNext() {
  return ((_x <= _index_x) && (_index_x < (_x + _w)) && (_y <= _index_y) && (_index_y < (_y + _h)));
  //return ((_index < _map_size) && (_index >= 0));
}

Background::Type *SimpleBackgroundMap::SBM_Iterator::next() {
  unsigned int index = CoordConverter::coordsToIndex(_index_x, _index_y, _map->_WIDTH);
  Background::Type *ret = &_map->_tiles[index];
  if (_index_x == (_x + _w - 1)) {
    _index_x = _x;
    _index_y++;
  }
  else {
    _index_x++;
  }
  return ret;
  //Background::Type ret = _tiles[_index];
  //_index++;
  //return ret;
}

BackgroundMap::Iterator *SimpleBackgroundMap::createIterator() {
  return new SBM_Iterator(this, 0, 0, _WIDTH, _HEIGHT);
}

BackgroundMap::Iterator *SimpleBackgroundMap::createIterator(const unsigned int& x,
                                                             const unsigned int& y,
                                                             const unsigned int& w,
                                                             const unsigned int& h) {
  unsigned int mx = x, my = y, mw = w, mh = h;
  _shrinkToFit(mx, my, mw, mh);
  return new SBM_Iterator(this, mx, my, mw, mh);
}

bool SimpleBackgroundMap::_isInRange(const unsigned int& index) const {
  return ((index >= 0) && (index < _SIZE));
}

void SimpleBackgroundMap::_shrinkToFit(unsigned int& x, unsigned int& y,
                                       unsigned int& w, unsigned int& h) {
  if ((x >= _WIDTH) || (y >= _HEIGHT)) {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    return;
  }
  if ((x + w) > _WIDTH) {
    w = _WIDTH - x;
  }
  if ((y + h) > _HEIGHT) {
    h = _HEIGHT - y;
  }
}
