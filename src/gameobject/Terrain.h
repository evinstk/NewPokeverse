#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <vector>

class Terrain {
 public:
  friend class TerrainPrototyper;
  Terrain();
  Terrain(const unsigned& type_id, const char& elevation = 0);

  unsigned getType() const;
  std::string getDescription() const;
  bool isWalkable() const;
  char getElevation() const;

  void setType(const unsigned& type_id);
  void setElevation(const char& elevation);
  char increaseElevation();
  char decreaseElevation();
 private:
  struct _TypeData {
    std::string description;
    bool walkable;
    _TypeData();
  };
  unsigned _type_id;
  char _elevation;
  static std::vector<_TypeData> _terrain_prototypes;

  static _TypeData _getData(const unsigned& index);
};

#endif /* TERRAIN_H */
