#ifndef SIMPLE_TM_H
#define SIMPLE_TM_H

#include "TerrainMapImp.h"
#include "gameobject/Terrain.h"

/**
 * Class: SimpleTM
 * ===============
 * Implementation of BackgroundMap base class.
 * Uses dynamically allocated array to collect
 * Background::Type tiles. Implements
 * appropriate Iterator.
 */
class SimpleTM: public TerrainMapImp {
 public:
  SimpleTM(const unsigned int& width, const unsigned int& height,
	     const unsigned& default_type = 0);
  ~SimpleTM();

  unsigned getType(const unsigned int& x, const unsigned int& y) const;
  void setType(const unsigned& type, const unsigned int& x, const unsigned int& y);
  bool isWalkable(const unsigned int& x, const unsigned int& y) const;
  char getElevation(const unsigned int& x, const unsigned int& y) const;

  char increaseElevation(const unsigned int& x, const unsigned int& y);
  char decreaseElevation(const unsigned int& x, const unsigned int& y);

  unsigned int getWidth() const;
  unsigned int getHeight() const;
  unsigned long getSize() const;
 private:
  Terrain *_tiles;
  const unsigned int _WIDTH;
  const unsigned int _HEIGHT;
  const unsigned long _SIZE;

  bool _isInRange(const unsigned long& index) const;
  bool _allAdjacentsEqualOrHigher(const unsigned int& x, const unsigned int& y) const;
  bool _allAdjacentsEqualOrLower(const unsigned int& x, const unsigned int& y) const;
};

#endif /* SIMPLE_TM_MAP_H */
