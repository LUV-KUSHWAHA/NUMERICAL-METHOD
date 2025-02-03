#include <stdio.h>
#include <math.h>

float g( float x)  // function: x*x + x -2 = 0
{
    //  return 2 - pow(x,2); // x0 = 0
    return sqrt( 2 - x); // x0 = 1
}

int main()
{
    int count = 0;
    float x0 = 1, x1, e, E = 0.001;
    do {
        count++;
        x1 = g(x0);
        e = x1 - x0;
        printf("%d x1 = %f\n", count, x1);
        x0 = x1;
    }while(fabs(e)>E);
    return 0;
}