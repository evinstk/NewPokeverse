#include "DoodadPrototyper.h"

std::vector<std::string> DoodadPrototyper::_descriptions;

unsigned DoodadPrototyper::registerPrototype(std::string description,
                                             const unsigned char& width,
					     const unsigned char& height) {
  unsigned index = Doodad::_doodad_prototypes.size();
  Doodad::TypeData type_data;
  type_data.description = description;
  type_data.w = width;
  type_data.h = height;
  Doodad::_doodad_prototypes.push_back(type_data);
  return index;
}
