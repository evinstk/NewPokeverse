#include "TerrainPrototyper.h"

unsigned TerrainPrototyper::registerPrototype(std::string description, bool walkable) {
  unsigned index = Terrain::_terrain_prototypes.size();
  Terrain::_TypeData type_data;
  type_data.description = description;
  type_data.walkable = walkable;
  Terrain::_terrain_prototypes.push_back(type_data);
  return index;
}
