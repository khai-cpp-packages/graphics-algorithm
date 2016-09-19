#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include "circle.hpp"
#include "bgipx.hpp"

int main () {
  int gdriver = DETECT, gmode, count;
  cout << "How many circle? ";
  cin >> count;
  randomize();
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  const PixelCoord maxx = getmaxx(), maxy = getmaxy(), radius = (min2v(maxx, maxy) >> 1) / count;
  const Pixel center(maxx >> 1, maxy >> 1);
  while (count--) {
    circle(center, radius * count, random(15), NULL, bgipx);
  }
  getch();
  closegraph();
  return 0;
}
