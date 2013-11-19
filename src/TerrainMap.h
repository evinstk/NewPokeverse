#ifndef TERRAIN_MAP_H
#define TERRAIN_MAP_H

#include "TerrainMapImp.h"

/**
 * Base Class: TerrainMap
 * ======================
 * Interface for interacting with a map composed
 * of Background tiles. Collection class. To be
 * used in more complex maps.
 *
 * Allows "paintbrush" operations/iterations.
 * May parameterize setType() and
 * createIterator() with rectangle position and
 * dimensions, and the object will perform the
 * operation over the corresponding tiles. (May
 * eventually need to encapsulate this behavior in
 * separate class in order to provide additional
 * functionality more easily. For now, the built-
 * in class is enough.)
 */
class TerrainMap {
 public:
  TerrainMap(TerrainMapImp *imp);
  ~TerrainMap();

  virtual unsigned getTerrain(const unsigned int& x, const unsigned int& y) const;
  virtual bool isWalkable(const unsigned int& x, const unsigned int& y) const;
  virtual char getElevation(const unsigned int& x, const unsigned int& y) const;

  virtual void setTerrain(const unsigned& type, const unsigned int& x, const unsigned int& y);
  virtual char increaseElevation(const unsigned int& x, const unsigned int& y);
  virtual char decreaseElevation(const unsigned int& x, const unsigned int& y);

  virtual unsigned int getWidth() const;
  virtual unsigned int getHeight() const;
  virtual unsigned long getSize() const;
 private:
  TerrainMapImp *_imp;
};

#endif /* TERRAIN_MAP_H */
