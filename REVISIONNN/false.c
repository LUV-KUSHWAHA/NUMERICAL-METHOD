#include <stdio.h>
#include <math.h>

float fun ( float x)
{
    return x*tan(x) - 1;
    // return 4*sin(x) - exp(x);
    // return x*x -4*x -10;
}

int main()
{
    int count = 0;
    float x1,x2,x0,f1,f2, f0, E=0.001;
    do{
        printf("Enter x1 and x2: ");
        scanf("%f%f", &x1, &x2);
        f1 = fun(x1);
        f2 = fun(x2);
        if(f1*f2 >0)
            printf("f1*f2 should be <0...\n");
    }while(f1*f2>0);

    do{
        count++;
        x0 = (x1 *f2 - x2 * f1)/ (f2 - f1);
        f0 = fun(x0);
        printf("\n%d x0 = %f", count, x0);
        if(f0 * f1 > 0)
        {
            x1 = x0;
            f1 = f0;
        }
        else{
            x2 = x0;
            f2 = f0;
        }
    }while(fabs(f0)>E);
    printf("\nRoot = %f", x0);
    return 0;
}