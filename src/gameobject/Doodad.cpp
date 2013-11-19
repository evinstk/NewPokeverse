#include "Doodad.h"

std::vector<Doodad::TypeData> Doodad::_doodad_prototypes;

//Doodad::Doodad(): Positionable<unsigned int>(0,0), _type_id(0) {}

Doodad::Doodad(const unsigned& type_id, const unsigned int& x, const unsigned int& y):
  Positionable<unsigned int>(x,y), _type_id(type_id) {}

unsigned Doodad::getType() const {
  return _type_id;
}

std::string Doodad::getDescription() const {
  std::string description = _doodad_prototypes[_type_id].description;
  return description;
}

unsigned char Doodad::getWidth() const {
  unsigned char w = _doodad_prototypes[_type_id].w;
  return w;
}

unsigned char Doodad::getHeight() const {
  unsigned char h = _doodad_prototypes[_type_id].h;
  return h;
}
