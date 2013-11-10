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
  SimpleBackgroundMap(const unsigned int& width,
                      const unsigned int& height,
                      const Background::Type& default_type = Background::GRASS);
  ~SimpleBackgroundMap();

  Background::Type getType(const unsigned int& x, const unsigned int& y) const;
  void setType(const Background::Type& type, const unsigned int& x, const unsigned int& y);
  Iterator *createIterator();
 private:
  /* Iterator implementation made private to avoid abuse. createIterator()
     should properly construct Iterator object. */
  class SBM_Iterator: public Iterator {
  public:
    SBM_Iterator(Background::Type *tiles, unsigned int map_size);
    bool hasNext();
    Background::Type next();
  private:
    unsigned int _index;
    Background::Type *_tiles;
    unsigned int _map_size;
  };
  Background::Type *_tiles;
  const unsigned int _WIDTH;
  const unsigned int _HEIGHT;
  const unsigned int _SIZE;

  unsigned int _coordsToIndex(const unsigned int& x, const unsigned int& y) const;
  bool _isInRange(const unsigned int& index);
};

#endif /* SIMPLE_BACKGROUND_MAP_H */
