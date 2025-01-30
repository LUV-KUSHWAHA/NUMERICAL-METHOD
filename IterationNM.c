#include <stdio.h>
#include <math.h>
float g1(float x){ return 2-x*x;} 
float g2(float x){ return sqrt(5);} 
void ROOT(float x0, float (*fun)(float))
{ 
    int count = 0; 
    float x1,E=0.0001,e; 
    do 
    { 
        count++; 
        x1 = (*fun)(x0); 
        e=x1-x0; 
        x0 = x1; 
        printf("\n %d x0 = %f",count,x0); 
    }while(fabs(e)>E); 
    printf("\nRoot = %f",x1);
} 
int main() 
{ 
    printf("\nFor fun1, x0 = 0"); 
    ROOT(0,g1); 
    printf("\nFor fun2, x0 = 3"); 
    ROOT(3,g2); 
    return 0; 
}