#ifndef DOODAD_PROTOTYPER_H
#define DOODAD_PROTOTYPER_H

#include "Doodad.h"
#include <string>
#include <vector>

/**
 * Class: DoodadPrototyper
 * =======================
 * Friend class of Doodad that adds and removes prototypes.
 * Decoupled from Doodad class so that clients of Doodad
 * do not irresponsibly add or remove prototypes.
 */
class DoodadPrototyper {
 public:
  static unsigned registerPrototype(std::string description, const unsigned char& width, const unsigned char& height);
 private:
  static std::vector<std::string> _descriptions;
};

#endif /* DOODAD_PROTOTYPER_H */
