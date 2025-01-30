#include<stdio.h>
#include<math.h>

float sam(float x)
{
    return 4*sin(x)-exp(x);
}
int main ()
{   int count =0;
    float x1=0,x2=1,E=0.0001,f1,f0,x0;
    do{
        count++;
        f1=sam(x1);
        x0=(x1+x2)/2;
        f0=sam(x0);
        printf("\n%d x0=%f",count,x0);
        if((f1*f0)>0)
        {
            x1=x0;
        }
         else {x2=x0;}
    }while(fabs((x2-x1)/x2)>E);
    printf("X0=%f",x0);
    return 0;
}
