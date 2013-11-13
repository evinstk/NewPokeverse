#ifndef SIMPLE_DOODAD_MAP
#define SIMPLE_DOODAD_MAP

#include "DoodadMap.h"
#include "BackgroundMap.h"
#include "util/CoordConverter.h"
#include <map>

/**
 * Class: SimpleDoodadMap
 * ======================
 * Implements DoodadMap using standard container
 * map to collect Doodad objects. Constructor
 * requires implementation of BackgroundMap so
 * that SimpleDoodadMap design is decoupled from
 * concrete class.
 *
 * The default implementation uses a
 * SimpleBackgroundMap in createBackgroundMap(),
 * but it may be overridden through subclasses.
 */
class SimpleDoodadMap: public DoodadMap {
 public:
  SimpleDoodadMap(BackgroundMap *background_map);

  void setBackground(const Background::Type& type,
		     const unsigned int& x,
		     const unsigned int& y);
  bool setDoodad(const int& type, const unsigned int& x, const unsigned int& y);
  bool removeDoodad(const unsigned int& x, const unsigned int& y);

  Background::Type getBackground(const unsigned int& x, const unsigned int& y) const;
  Doodad getDoodad(const unsigned int& x, const unsigned int& y) const;

  unsigned int getWidth() const;
  unsigned int getHeight() const;
  unsigned int getSize() const;
 private:
  BackgroundMap *_background_map;
  std::map<unsigned int, Doodad> _doodads;
};

#endif /* SIMPLE_DOODAD_MAP */
