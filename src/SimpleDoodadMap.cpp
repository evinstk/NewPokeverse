#include "SimpleDoodadMap.h"
#include "util/CoordConverter.h"

SimpleDoodadMap::SimpleDoodadMap(BackgroundMap *background_map) {
  _background_map = background_map;
}

void SimpleDoodadMap::setBackground(const Background::Type& type,
				    const unsigned int& x,
				    const unsigned int& y) {
  _background_map->setType(type, x, y);
}

bool SimpleDoodadMap::setDoodad(const int& type,
                                const unsigned int& x,
                                const unsigned int& y) {
  Doodad d = Doodad::findAndClone(type);
  unsigned int index = CoordConverter::coordsToIndex(x, y, _background_map->getWidth());
  if ((d.getType() != Doodad::NO_DOODAD) && (index < _background_map->getSize())) {
    _doodads[index] = d;
    return true;
  }
  return false;
}

bool SimpleDoodadMap::removeDoodad(const unsigned int& x, const unsigned int& y) {
  unsigned int index = CoordConverter::coordsToIndex(x, y, _background_map->getWidth());
  std::map<unsigned int, Doodad>::iterator it = _doodads.find(index);
  if (it == _doodads.end()) return false;
  _doodads.erase(it);
  return true;
}

Background::Type SimpleDoodadMap::getBackground(const unsigned int& x,
                                                const unsigned int& y) const {
  Background::Type ret = _background_map->getType(x, y);
  return ret;
}

Doodad SimpleDoodadMap::getDoodad(const unsigned int& x, const unsigned int& y) const {
  unsigned int index = CoordConverter::coordsToIndex(x, y, _background_map->getWidth());
  Doodad ret;
  try {
    ret = _doodads.at(index);
  }
  catch (const std::exception& e) {
    ret = Doodad();
  }
  return ret;
}

unsigned int SimpleDoodadMap::getWidth() const {
  unsigned int w = _background_map->getWidth();
  return w;
}

unsigned int SimpleDoodadMap::getHeight() const {
  unsigned int h = _background_map->getHeight();
  return h;
}

unsigned int SimpleDoodadMap::getSize() const {
  unsigned int s = _background_map->getSize();
  return s;
}
