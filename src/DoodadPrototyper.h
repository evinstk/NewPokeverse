#ifndef DOODAD_PROTOTYPER_H
#define DOODAD_PROTOTYPER_H

#include "doodad.h"

/**
 * Class: DoodadPrototyper
 * =======================
 * Friend class of Doodad that adds and removes prototypes.
 * Decoupled from Doodad class so that clients of Doodad
 * do not irresponsibly add or remove prototypes.
 */
class DoodadPrototyper {
 public:
  static bool addPrototype(const Doodad::BuiltInType& type,
			   const unsigned char& width,
			   const unsigned char& height);
  static bool addPrototype(const int& type,
			   const unsigned char& width,
			   const unsigned char& height);
  static bool removePrototype(const int& type);
};

#endif /* DOODAD_PROTOTYPER_H */
