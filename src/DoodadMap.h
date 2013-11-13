#ifndef DOODAD_MAP_H
#define DOODAD_MAP_H

#include "Doodad.h"
#include "Background.h"

/**
 * Base Class: DoodadMap
 * =====================
 * Abstract base class for implementations of DoodadMap.
 * DoodadMap should offer all functionality of
 * BackgroundMap as well as additional functionality
 * for decorating the map with unmoving objects.
 *
 * DoodadMap does virtually no placement enforcement.
 * Interacting with the Doodad class directly allows the
 * client to place Doodads anywhere, including
 * contradictory positions. Placement restriction is
 * handled by other class(es) (yet to be determined).
 * This freedom is to make DoodadMap functionality
 * simple and unconfusing.
 *
 * getDoodad() only returns a Doodad if its top-left
 * corner is at the given coordinates. DoodadMap does
 * not factor in a Doodad object's dimensions.
 */
class DoodadMap {
 public:
  virtual void setBackground(const Background::Type& type,
			     const unsigned int& x,
			     const unsigned int& y) = 0;
  virtual bool setDoodad(const int& type, const unsigned int& x, const unsigned int& y) = 0;
  virtual bool removeDoodad(const unsigned int& x, const unsigned int& y) = 0;

  virtual Background::Type getBackground(const unsigned int& x,
                                         const unsigned int& y) const = 0;
  virtual Doodad getDoodad(const unsigned int& x, const unsigned int& y) const = 0;

  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual unsigned int getSize() const = 0;
};

#endif /* DOODAD_MAP_H */
