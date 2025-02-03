
//  Given equation: y1 -3*x*x = 1, with y(1) = 2. Estimate y(2.5) using h = 0.25 and 0.5 respectively.
#include <math.h>
#include <stdio.h>

float fun( float x, float y) { return 1 + 3 * x * x; }

int main()
{
    int i, n;
    float x = 1, y= 2, xp = 2.5, h = 0.25;
    float m1, m2;
    n = (xp - x)/h;
    for(i=0; i<n; i++)
    {
        m1 = fun(x,y);
        m2 = fun(x+h, y+m1);
        y += h/2*(m1 + m2);
        x += h;
    }
    printf("y = %f", y);
    return 0;
}