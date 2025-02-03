#include <stdio.h>
#include <math.h>

float fun( float x) { return pow(x,2) -4*x -10; }
float dfun(float x) { return 2*x - 4; }

int main()
{
    int count = 0;
    float x0, f0, df0, E= 0.001;
    printf("Enter any number: ");
    scanf("%f", &x0);
    do {
        count++;
        f0 = fun(x0);
        df0 = dfun(x0);
        x0 -= f0/df0;
        printf("%d x0 = %f\n", count, x0);
    }while(fabs(f0/df0)> E);
    printf("Root = %f", x0);
    return 0;
}