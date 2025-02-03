#include <stdio.h>
#include <math.h>

float fun( float x)
{
    return 4*sin(x) - exp(x);
    // return pow(x,2) -4*x -10;
}

int main()
{
    int count = 0;
    float x1, x2, x3, f1, f2, f3, E = 0.001;
    do {
        printf("Enter x1 and x2: ");
        scanf("%f%f", &x1, &x2);
        f1 = fun(x1);
        f2 = fun(x2);
        if(f1*f2 > 0)
            printf("f1*f2 should be > 0...\n");
    }while(f1*f2 >0);
    do {
        count++;
        x3 = (x1 *f2 - x2 * f1)/(f2 -f1);
        f3 = fun(x3);
        printf("%d x3 = %f\n", count, x3);
        x1 = x2;
        f1 = f2;
        x2 = x3;
        f2 = f3;
    }while(fabs((x2 - x1)/x2)>E);
    printf("\nRoot = %f", x3);
    return 0;
}