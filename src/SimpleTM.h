#ifndef SIMPLE_TM_H
#define SIMPLE_TM_H

#include "TiledMapImp.h"
#include "Background.h"

/**
 * Class: SimpleBackgroundMap
 * ==========================
 * Implementation of BackgroundMap base class.
 * Uses dynamically allocated array to collect
 * Background::Type tiles. Implements
 * appropriate Iterator.
 */
class SimpleTM: public TiledMapImp {
 public:
  SimpleTM(const unsigned int& width, const unsigned int& height,
	     const int& type = Background::GRASS);
  ~SimpleTM();

  int getType(const unsigned int& x, const unsigned int& y) const;
  void setType(const int& type, const unsigned int& x, const unsigned int& y);
  unsigned int getWidth() const;
  unsigned int getHeight() const;
  unsigned long getSize() const;
 private:
  int *_tiles;
  const unsigned int _WIDTH;
  const unsigned int _HEIGHT;
  const unsigned long _SIZE;

  bool _isInRange(const unsigned int& index) const;
  void _shrinkToFit(unsigned int& x, unsigned int& y, unsigned int& w, unsigned int& h);
};

#endif /* SIMPLE_TM_MAP_H */
