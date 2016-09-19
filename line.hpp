#if !defined(_INCLUDE_LINE_HPP)
#define _INCLUDE_LINE_HPP 20160919

#include <stdlib.h>
#include "utils.hpp"
#include "pixel.hpp"

void linePointPoint (Pixel, Pixel, Color, PixelProc);
void linePointTrans (Pixel, Pixel, Color, PixelProc);
void __line_checkdx (Pixel, Pixel, Color, void *, PixelProc);
void __line_checkdy (Pixel, Pixel, Color, void *, PixelProc);
void __line_cmpdxdy (Pixel, Pixel, Color, void *, PixelProc);
void __line_base (Pixel, Pixel, Color, void *, PixelProc);
void __lChkDy_positive (Pixel, Color, void *);
void __lChkDy_negative (Pixel, Color, void *);
void __lCmpDxDy_positive (Pixel, Color, void *);
void __lCmpDxDy_negative (Pixel, Color, void *);
void __lBase_positive (Pixel, Color, void *);
void __lBase_negative (Pixel, Color, void *);

void linePointPoint (Pixel begin, Pixel end, Color color, PixelProc px) {
  __line_checkdx(begin, end - begin, color, NULL, px);
}

void linePointTrans (Pixel v, Pixel dv, Color color, PixelProc px) {
  __line_checkdx(v, dv, color, NULL, px);
}

void __line_checkdx (Pixel v, Pixel dv, Color color, void *, PixelProc px) {
  if (dv.x > 0) {
    __line_checkdy(v, dv, color, NULL, px);
  } else {
    __line_checkdy(v + dv, -dv, color, NULL, px);
  }
}

void __line_checkdy (Pixel v, Pixel dv, Color color, void *, PixelProc px) {
  if (dv.y > 0) {
    __line_cmpdxdy(v, dv, color, (void *) px, __lChkDy_positive);
  } else {
    __line_cmpdxdy(Pixel(v.x, -v.y), Pixel(dv.x, -dv.y), color, (void *) px, __lChkDy_negative);
  }
}

void __line_cmpdxdy (Pixel v, Pixel dv, Color color, void * param, PixelProc px) {
  BoundPixelProc * pair = new BoundPixelProc(px, param);
  if (dv.x > dv.y) {
    __line_base(v, dv, color, (void *) pair, __lCmpDxDy_positive);
  } else {
    __line_base(v.swap(), dv.swap(), color, (void *) pair, __lCmpDxDy_negative);
  }
  delete pair;
}

void __line_base (Pixel v, Pixel dv, Color color, void * param, PixelProc px) {
  PixelCoord p = (dv.y << 1) - dv.x;
  const PixelCoord dp1 = dv.y << 1;
  const PixelCoord dp2 = (dv.y - dv.x) << 1;
  PixelCoord endx = v.x + dv.x;
  for (Pixel iv = v; iv.x != endx; ++iv.x) {
    px(iv, color, param);
    if (p < 0) {
      p += dp1;
    } else {
      p += dp2;
      ++iv.y;
    }
  }
}

void __lChkDy_positive (Pixel px, Color color, void * param) {
  ((PixelProc) param)(px, color, NULL);
}

void __lChkDy_negative (Pixel px, Color color, void * param) {
  ((PixelProc) param)(Pixel(px.x, -px.y), color, NULL);
}

void __lCmpDxDy_positive (Pixel px, Color color, void * param) {
  ((BoundPixelProc *) param)->call(px, color);
}

void __lCmpDxDy_negative (Pixel px, Color color, void * param) {
  ((BoundPixelProc *) param)->call(px.swap(), color);
}

#endif // _INCLUDE_LINE_HPP
