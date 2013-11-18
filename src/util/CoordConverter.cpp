#include "CoordConverter.h"

unsigned long CoordConverter::coordsToIndex(const unsigned int& x,
                                           const unsigned int& y,
					   const unsigned int& width) {
  unsigned long ret = ((y * width) + x);
  return ret;
}

CoordConverter::Point CoordConverter::indexToCoords(const unsigned int& index,
                                                    const unsigned int& width) {
  Point p;
  p.x = index % width;
  p.y = index / width;
  return p;
}
