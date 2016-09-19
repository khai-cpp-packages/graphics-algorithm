#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include "line.hpp"
#include "bgipx.hpp"

int main () {
  int gdriver = DETECT, gmode, count;
  cout << "How many lines? ";
  cin >> count;
  randomize();
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  const PixelCoord maxx = getmaxx(), maxy = getmaxy();
  const Pixel center(maxx >> 1, maxy >> 1);
  while (count--) {
    linePointPoint(center, Pixel(random(maxx), random(maxy)), random(15), bgipx);
  }
  getch();
  closegraph();
  return 0;
}
