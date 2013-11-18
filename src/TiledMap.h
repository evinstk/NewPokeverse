#ifndef TILED_MAP_H
#define TILED_MAP_H

#include "TiledMapImp.h"

/**
 * Base Class: TiledMap
 * ====================
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
class TiledMap {
 public:
  TiledMap(TiledMapImp *imp);
  ~TiledMap();

  virtual int getTile(const unsigned int& x, const unsigned int& y) const;
  virtual void setTile(const int& type, const unsigned int& x, const unsigned int& y);
  virtual unsigned int getWidth() const;
  virtual unsigned int getHeight() const;
  virtual unsigned long getSize() const;
 private:
  TiledMapImp *_imp;
};

#endif /* TILED_MAP_H */
