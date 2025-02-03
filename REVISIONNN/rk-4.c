//  Given equation: y1 -3*x*x = 1, with y(1) = 2. Estimate y(2.5) using h = 0.25 and 0.5 respectively.
#include <stdio.h>
#include <math.h>

float fun(float x, float y) { return 1 + 3 *x*x; }

int main()
{
    int i, n;
    float x=1, y=2, xp=2.5, h=0.5;
    float m1, m2, m3, m4;
    n = (xp-x)/h;
    for(i=0; i<n; i++)
    {
        m1 = fun(x,h);
        m2 = fun(x + h/2, y + m1/2);
        m3 = fun(x + h/2, y+ m2/2);
        m4 = fun(x+h, y+m3);
        y += h/6*(m1 + 2*m2 + 2*m3 +m4);
        x += h;
    }
    printf("y = %f", y);
    return 0;
}