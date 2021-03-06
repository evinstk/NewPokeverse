#ifndef DOODAD_H
#define DOODAD_H

#include <vector>

/**
 * Class: Doodad
 * =============
 * Variation on the prototype design pattern. The Doodad
 * class manages instances of itself. We avoid subclassing
 * since instances of Doodad do not offer any different
 * functionality, only differences in constants. Supports
 * custom Doodads by dynamically registering new prototypes
 * provided that the type index is not already registered.
 *
 * Doodads represent unmoving objects that typically
 * decorate a BackgroundMap. Doodad objects do not know
 * their position (if there is one) or context. They only
 * know their dimensions.
 *
 * Doodad is not responsible for adding or removing
 * prototypes. A separate class DoodadPrototyper does this
 * for Doodad, so that clients of Doodad may use pre-
 * existing Doodad objects without danger. Doodad makes
 * no calls to DoodadPrototyper.
 *
 * For improvements, Consider offering two varieties of
 * support: fast but inflexible hard-wired approach for
 * built-in types while keeping a cache for custom
 * prototypes.
 */
class Doodad {
 public:
  friend class DoodadPrototyper;
  enum BuiltInType {
    NO_DOODAD, TREE, BUSH
  };
  Doodad();
  static Doodad findAndClone(const int& type);

  /* Instance-specific methods */
  int getType() const;
  unsigned char getWidth() const;
  unsigned char getHeight() const;
 private:
  Doodad(const int& type, const unsigned char& width, const unsigned char& height);
  static std::vector<Doodad> _prototypes;
  static int _next_slot;

  int _type;
  unsigned char _w;
  unsigned char _h;

  static int _getIndex(const int& type);
};

#endif /* DOODAD_H */
