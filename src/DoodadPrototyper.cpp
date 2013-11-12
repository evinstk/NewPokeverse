#include "DoodadPrototyper.h"

bool DoodadPrototyper::addPrototype(const Doodad::BuiltInType& type,
                          const unsigned char& width,
                          const unsigned char& height) {
  addPrototype((int)type, width, height);
}

bool DoodadPrototyper::addPrototype(const int& type,
                          const unsigned char& width,
                          const unsigned char& height) {
  if (Doodad::_getIndex(type) != -1) return false;
  Doodad doodad(type, width, height);
  Doodad::_prototypes.push_back(doodad);
  Doodad::_next_slot++;
  return true;
}

bool DoodadPrototyper::removePrototype(const int& type) {
  int index = Doodad::_getIndex(type);
  if (index == -1) return false;
  Doodad::_prototypes.erase(Doodad::_prototypes.begin()+index);
  return true;
}
