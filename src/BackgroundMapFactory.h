#ifndef BACKGROUND_MAP_FACTORY
#define BACKGROUND_MAP_FACTORY

#include "BackgroundMap.h"

class BackgroundMapFactory {
 public:
  enum MapType {
    SIMPLE
  };
  static BackgroundMap *createBackgroundMap(const MapType& map_type,
					    const unsigned int& width,
					    const unsigned int& height,
                                            const Background::Type& default_bg = Background::GRASS);
};

#endif /* BACKGROUND_MAP_FACTORY */
