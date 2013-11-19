#ifndef DOODAD_H
#define DOODAD_H

#include "Positionable.h"
#include <vector>
#include <string>

class Doodad: public Positionable<unsigned int> {
 public:
  friend class DoodadPrototyper;
  Doodad(const unsigned& type_id, const unsigned int& x, const unsigned int& y);

  unsigned getType() const;
  std::string getDescription() const;
  unsigned char getWidth() const;
  unsigned char getHeight() const;
 private:
  struct TypeData {
    std::string description;
    unsigned char w;
    unsigned char h;
  };
  const unsigned _type_id;
  static std::vector<TypeData> _doodad_prototypes;
};

#endif /* DOODAD_H */
