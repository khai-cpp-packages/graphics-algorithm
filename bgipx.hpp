#if !defined(_INCLUDE_BGIPX_HPP)
#define _INCLUDE_BGIPX_HPP 20160919

#include <graphics.h>
#include "line.hpp"

void bgipx (Pixel pixel, Color color, void * = NULL) {
  putpixel(pixel.x, pixel.y, color);
}

#endif // _INCLUDE_BGIPX_HPP
