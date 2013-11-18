#include "TiledMap.h"

TiledMap::TiledMap(TiledMapImp *imp): _imp(imp) {}

TiledMap::~TiledMap() {
  delete _imp;
}

int TiledMap::getTile(const unsigned int& x, const unsigned int& y) const {
  return _imp->getType(x, y);
}

void TiledMap::setTile(const int& type, const unsigned int& x, const unsigned int& y) {
  _imp->setType(type, x, y);
}

unsigned int TiledMap::getWidth() const {
  return _imp->getWidth();
}

unsigned int TiledMap::getHeight() const {
  return _imp->getHeight();
}

unsigned long TiledMap::getSize() const {
  return _imp->getSize();
}
