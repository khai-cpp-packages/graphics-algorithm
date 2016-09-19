#if !defined(_INCLUDE_VEC_HPP)
#define _INCLUDE_VEC_HPP 20160919

template <class Coord>
struct Vec {
  Coord x, y;
  Vec (Coord vx = 0, Coord vy = 0) : x(vx), y(vy) {}
  Coord & operator [] (int index) {
    return ((Coord *)(this))[index];
  }
  Vec operator + (Vec<Coord> v) {
    return Vec<Coord>(x + v.x, y + v.y);
  }
  Vec operator - (Vec<Coord> v) {
    return Vec<Coord>(x - v.x, y - v.y);
  }
  Vec operator + () {
    return * this;
  }
  Vec operator - () {
    return Vec<Coord>(-x, -y);
  }
  Vec swap () {
    return Vec<Coord>(y, x);
  }
};

#endif // _INCLUDE_VEC_HPP
