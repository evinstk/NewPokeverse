#include "BackgroundMapFactory.h"
#include "SimpleBackgroundMap.h"

BackgroundMap *BackgroundMapFactory::createBackgroundMap(const MapType& map_type,
							 const unsigned int& width,
							 const unsigned int& height,
							 const Background::Type& default_bg) {
  switch (map_type) {
  case SIMPLE: return new SimpleBackgroundMap(width, height, default_bg);
  }
}
