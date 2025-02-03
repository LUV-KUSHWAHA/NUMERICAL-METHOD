#include <stdio.h>
#include <math.h>

float fun(float x ) { return 1 + pow(x,3); }

int main()
{
    int i, n=15;
    float a=1, b=2, h, fa, fb, I, intSum1=0, intSum2=0;
    h = (b-a)/n;
    fa = fun(a);
    fb = fun(b);
    for(i=1; i<n; i++)
    {
        if(i%2 == 0)
            intSum2 += fun(a +i*h);
        else
            intSum1 += fun(a +i*h);
    }
    I = h/3*(fa + fb + 4*intSum1 + 2*intSum2);
    printf("ans = %f", I);
    return 0;
}