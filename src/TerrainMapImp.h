#ifndef TERRAIN_MAP_IMP_H
#define TERRAIN_MAP_IMP_H

class TerrainMapImp {
 public:
  virtual unsigned getType(const unsigned int& x, const unsigned int& y) const = 0;
  virtual void setType(const unsigned& type, const unsigned int& x, const unsigned int& y) = 0;
  virtual bool isWalkable(const unsigned int& x, const unsigned int& y) const = 0;
  virtual char getElevation(const unsigned int& x, const unsigned int& y) const = 0;

  virtual char increaseElevation(const unsigned int& x, const unsigned int& y) = 0;
  virtual char decreaseElevation(const unsigned int& x, const unsigned int& y) = 0;

  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual unsigned long getSize() const = 0;
};

#endif /* TERRAIN_MAP_IMP_H */
