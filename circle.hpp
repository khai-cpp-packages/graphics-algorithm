#if !defined(_INCLUDE_CIRCLE_HPP)
#define _INCLUDE_CIRCLE_HPP 20160919

#include <stdlib.h>
#include "pixel.hpp"

void circle (Pixel, PixelCoord, Color, void *, PixelProc);
void circle1p8 (Pixel, PixelCoord, Color, void *, DoublePixelProc);
void put8px (Pixel, Pixel, Color, void *);

void circle (Pixel center, PixelCoord radius, Color color, void * param, PixelProc px) {
  BoundPixelProc * pair = new BoundPixelProc(px, param);
  circle1p8(center, radius, color, NULL, put8px);
  delete pair;
}

void circle1p8 (Pixel center, PixelCoord radius, Color color, void * param, DoublePixelProc px) {
  PixelCoord p = 1 - radius, x = 0, y = radius;
  while (x < y) {
    px(center, Pixel(x, y), color, param);
    if (p < 0) {
      p += (x << 1) + 3;
    } else {
      p += ((x - y) << 1) + 5;
      --y;
    }
    ++x;
  }
}

void put8px (Pixel center, Pixel transl, Color color, void * param) {
  BoundPixelProc * fn = (BoundPixelProc *) param;
  fn->call(Pixel(center.x - transl.x, center.y - transl.y), color);
  fn->call(Pixel(center.x - transl.y, center.y - transl.x), color);
  fn->call(Pixel(center.x - transl.x, center.y + transl.y), color);
  fn->call(Pixel(center.x - transl.y, center.y + transl.x), color);
  fn->call(Pixel(center.x + transl.x, center.y - transl.y), color);
  fn->call(Pixel(center.x + transl.y, center.y - transl.x), color);
  fn->call(Pixel(center.x + transl.x, center.y + transl.y), color);
  fn->call(Pixel(center.x + transl.y, center.y + transl.x), color);
}

#endif // _INCLUDE_CIRCLE_HPP
