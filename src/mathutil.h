#include <stdbool.h>
#include <math.h>


// Vector 2
struct Vec2
{
    float x;
    float y;
} typedef Vec2;

// Rect
struct Rect
{
    Vec2 topLeft;
    Vec2 topRight;
    Vec2 botLeft;
    Vec2 botRight;
} typedef Rect;