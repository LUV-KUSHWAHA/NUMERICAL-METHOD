//  Given equation: y1 -3*x*x = 1, with y(1) = 2. Estimate y(2.5) using h = 0.25 and 0.5 respectively.

#include <stdio.h>
#include <math.h>

float fun(float x, float y) { return 1 + 3* pow(x,2); }

int main()
{
    int i, n;
    float x=1, y=2, xp=2.5, h=0.25;
    n = (xp - x)/h;
    for( i=0;i<n;i++)
    {
        y += h*fun(x,y);
        x += h;
    }
    printf("y = %f", y);
    return 0;
}