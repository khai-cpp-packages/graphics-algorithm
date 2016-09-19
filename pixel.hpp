#if !defined(_INCLUDE_PIXEL_HPP)
#define _INCLUDE_PIXEL_HPP 20160919

#include "vec.hpp"
#include "utils.hpp"

typedef int Color;
typedef int PixelCoord;
typedef Vec<PixelCoord> Pixel;
typedef void (* PixelProc) (Pixel, Color, void *);
typedef void (* DoublePixelProc) (Pixel, Pixel, Color, void *);

struct BoundPixelProc : Pair<PixelProc, void *> {
  BoundPixelProc () {}
  BoundPixelProc (PixelProc fn, void * param = NULL) : Pair<PixelProc, void *>(fn, param) {}
  PixelProc getFunction () {
    return a;
  }
  void setFunction (PixelProc fn) {
    a = fn;
  }
  void * getParam () {
    return b;
  }
  void setParam (void * lp) {
    b = lp;
  }
  void call (Pixel px, Color color) {
    a(px, color, b);
  }
  void operator () (Pixel px, Color color) {
    call(px, color);
  }
};

#endif // _INCLUDE_PIXEL_HPP
