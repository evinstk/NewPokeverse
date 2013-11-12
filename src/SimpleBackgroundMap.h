#ifndef SIMPLE_BACKGROUND_MAP_H
#define SIMPLE_BACKGROUND_MAP_H

#include "BackgroundMap.h"

/**
 * Class: SimpleBackgroundMap
 * ==========================
 * Implementation of BackgroundMap base class.
 * Uses dynamically allocated array to collect
 * Background::Type tiles. Implements
 * appropriate Iterator.
 */
class SimpleBackgroundMap: public BackgroundMap {
 public:
  friend class SBM_Iterator;
  SimpleBackgroundMap(const unsigned int& width,
                      const unsigned int& height,
                      const Background::Type& default_type = Background::GRASS);
  ~SimpleBackgroundMap();

  Background::Type getType(const unsigned int& x, const unsigned int& y) const;
  void setType(const Background::Type& type, const unsigned int& x, const unsigned int& y,
               const unsigned int& w = 1, const unsigned int& h = 1);
  unsigned int getWidth() const;
  unsigned int getHeight() const;
  unsigned int getSize() const;
  Iterator *createIterator();
  Iterator *createIterator(const unsigned int& x, const unsigned int& y,
                           const unsigned int& w, const unsigned int& h);
 private:
  /* Iterator implementation made private to avoid abuse. createIterator()
     should properly construct Iterator object. */
  class SBM_Iterator: public Iterator {
  public:
    SBM_Iterator(SimpleBackgroundMap *map, const unsigned int& x, const unsigned int& y,
                 const unsigned int& w, const unsigned int& h);
    bool hasNext();
    Background::Type *next();
  private:
    unsigned int _index_x, _index_y, _x, _y, _w, _h;
    SimpleBackgroundMap *_map;
  };
  Background::Type *_tiles;
  const unsigned int _WIDTH;
  const unsigned int _HEIGHT;
  const unsigned int _SIZE;

  unsigned int _coordsToIndex(const unsigned int& x, const unsigned int& y) const;
  bool _isInRange(const unsigned int& index) const;
  void _shrinkToFit(unsigned int& x, unsigned int& y, unsigned int& w, unsigned int& h);
};

#endif /* SIMPLE_BACKGROUND_MAP_H */
