#ifndef TILED_MAP_IMP_H
#define TILED_MAP_IMP_H

class TiledMapImp {
 public:
  virtual int getType(const unsigned int& x, const unsigned int& y) const = 0;
  virtual void setType(const int& type, const unsigned int& x, const unsigned int& y) = 0;
  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual unsigned long getSize() const = 0;
};

#endif /* TILED_MAP_IMP_H */
