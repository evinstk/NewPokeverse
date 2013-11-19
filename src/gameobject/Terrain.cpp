#include "Terrain.h"

std::vector<Terrain::_TypeData> Terrain::_terrain_prototypes;

Terrain::Terrain(): _type_id(0), _elevation(0) {}

Terrain::Terrain(const unsigned& type_id, const char& elevation):
  _type_id(type_id), _elevation(elevation) {}

Terrain::_TypeData::_TypeData(): description("Default Terrain"), walkable(true) {}

unsigned Terrain::getType() const {
  return _type_id;
}

std::string Terrain::getDescription() const {
  std::string description = _getData(_type_id).description;
  return description;
}

bool Terrain::isWalkable() const {
  bool walkable = _getData(_type_id).walkable;
  return walkable;
}

char Terrain::getElevation() const {
  return _elevation;
}

void Terrain::setType(const unsigned& type_id) {
  _type_id = type_id;
}

void Terrain::setElevation(const char& elevation) {
  _elevation = elevation;
}

char Terrain::increaseElevation() {
  return ++_elevation;
}

char Terrain::decreaseElevation() {
  return --_elevation;
}

Terrain::_TypeData Terrain::_getData(const unsigned& index) {
  _TypeData data;
  if (index < _terrain_prototypes.size()) data = _terrain_prototypes[index];
  return data;
}
