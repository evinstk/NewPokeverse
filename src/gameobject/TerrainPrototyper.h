#ifndef TERRAIN_PROTOTYPER_H
#define TERRAIN_PROTOTYPER_H

#include "Terrain.h"

class TerrainPrototyper {
 public:
  static unsigned registerPrototype(std::string description, bool walkable);
};

#endif /* TERRAIN_PROTOTYPER_H */
