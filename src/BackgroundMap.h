#ifndef BACKGROUND_MAP_H
#define BACKGROUND_MAP_H

#include "Background.h"

/**
 * Base Class: BackgroundMap
 * =========================
 * Interface for interacting with a map composed
 * of Background tiles. Collection class. To be
 * used in more complex maps.
 */
class BackgroundMap {
 public:
  virtual Background::Type getType(const unsigned int& x, const unsigned int& y) const = 0;
  virtual void setType(const Background::Type& type, const unsigned int& x,
                       const unsigned int& y) = 0;
  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual unsigned int getSize() const = 0;
  class Iterator {
  public:
    virtual bool hasNext() = 0;
    virtual Background::Type next() = 0;
  };
  virtual Iterator *createIterator() = 0;
};

#endif /* BACKGROUND_MAP_H */
