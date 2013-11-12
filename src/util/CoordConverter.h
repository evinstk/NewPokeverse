#ifndef COORD_CONVERTER_H
#define COORD_CONVERTER_H

/**
 * Class: CoordConverter
 * =====================
 * Utility class to facilitate emulating two-dimensional
 * arrays in one-dimensional arrays. Converts x- and y-
 * coordinates into an equivalent index according to
 * width parameters and vice versa.
 */
class CoordConverter {
 public:
  struct Point { unsigned int x; unsigned int y; };
  static unsigned int coordsToIndex(const unsigned int& x, const unsigned int& y,
				    const unsigned int& width);
  static Point indexToCoords(const unsigned int& index, const unsigned int& width);
};

#endif /* COORD_CONVERTER_H */
