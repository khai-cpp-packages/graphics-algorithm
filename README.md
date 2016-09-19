# Collection of Raster Graphics Algorithm in C++

## Test

### Prerequisites

#### Define your pixel function

```c++
#include "pixel.hpp"
void drawPixel (Pixel position, Color color, void * param);
```

### Draw Line

#### Prerequisites

```c++
#include "line.hpp"
Color color;
```

#### From point `Pixel begin` to point `Pixel end`

```c++
linePointPoint(begin, end, color, drawPixel);
```

#### From point `Pixel begin = v` to point `Pixel end = v + dv`

```c++
linePointTrans(v, dv, color, drawPixel);
```

### Draw Circle

#### Prerequisites

```c++
#include "circle.hpp"
Pixel center;
PixelCoord radius;
```

#### Draw Full Circle

```c++
circle(center, radius, color, NULL, drawPixel);
```

#### Draw Circle-base Shape

##### Prerequisites

```c++
void drawMyShapePixel(Pixel center, Pixel transl, Color color, void * param);
void * param;
```

##### Code

```c++
circle1p8(center, radius, color, param, drawMyShapePixel);
```
