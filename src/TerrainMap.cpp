#include "TerrainMap.h"

TerrainMap::TerrainMap(TerrainMapImp *imp): _imp(imp) {}

TerrainMap::~TerrainMap() {
  delete _imp;
}

unsigned TerrainMap::getTerrain(const unsigned int& x, const unsigned int& y) const {
  return _imp->getType(x, y);
}

bool TerrainMap::isWalkable(const unsigned int& x, const unsigned int& y) const {
  return _imp->isWalkable(x, y);
}

char TerrainMap::getElevation(const unsigned int& x, const unsigned int& y) const {
  return _imp->getElevation(x, y);
}

void TerrainMap::setTerrain(const unsigned& type, const unsigned int& x, const unsigned int& y) {
  _imp->setType(type, x, y);
}

char TerrainMap::increaseElevation(const unsigned int& x, const unsigned int& y) {
  _imp->increaseElevation(x, y);
}

char TerrainMap::decreaseElevation(const unsigned int& x, const unsigned int& y) {
  _imp->decreaseElevation(x, y);
}

unsigned int TerrainMap::getWidth() const {
  return _imp->getWidth();
}

unsigned int TerrainMap::getHeight() const {
  return _imp->getHeight();
}

unsigned long TerrainMap::getSize() const {
  return _imp->getSize();
}
