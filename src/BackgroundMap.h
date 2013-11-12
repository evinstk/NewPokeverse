#ifndef BACKGROUND_MAP_H
#define BACKGROUND_MAP_H

#include "Background.h"

/**
 * Base Class: BackgroundMap
 * =========================
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
class BackgroundMap {
 public:
  virtual Background::Type getType(const unsigned int& x, const unsigned int& y) const = 0;
  virtual void setType(const Background::Type& type,
                       const unsigned int& x, const unsigned int& y,
                       const unsigned int& w = 1, const unsigned int& h = 1) = 0;
  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual unsigned int getSize() const = 0;
  class Iterator {
  public:
    virtual bool hasNext() = 0;
    virtual Background::Type *next() = 0;
  };
  virtual Iterator *createIterator() = 0;
  virtual Iterator *createIterator(const unsigned int& x, const unsigned int& y,
                                   const unsigned int& w, const unsigned int& h) = 0;
};

#endif /* BACKGROUND_MAP_H */
