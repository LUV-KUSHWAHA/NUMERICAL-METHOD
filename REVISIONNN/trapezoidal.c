#include <stdio.h>
#include <math.h>

float fun(float x ) { return 1 + pow(x,3); }

int main()
{
    int i, n=20;
    float a=1, b=2, h, fa, fb, I, intSum=0;
    h = (b-a)/n;
    fa = fun(a);
    fb = fun(b);
    for(i=1; i<n; i++)
    {
        intSum += fun(a +i*h);
    }
    I = h/2*(fa + fb + 2*intSum);
    printf("ans = %f", I);
    return 0;
}