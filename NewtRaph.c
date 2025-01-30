// NEWTON RAPHSON IMPLEMENTATION
#include <stdio.h>
#include <math.h>

float fun1(float x) {
    return x * x - 4 * x - 10;
}

float dfun1(float x) {
    return 2 * x - 4;
}

float fun2(float x) {
    return x * tan(x) - 1;
}

float dfun2(float x) {
    return tan(x) + x / (cos(x) * cos(x));
}

void ROOT(float x0, float (*fun)(float), float (*dfun)(float)) {
    int count = 0;
    float x1, f0, df0, E = 0.0001;
    printf("\nS.N.\t x0\t\t x1\t\t f0\t\t df0");
    printf("\n-------------------------------------------------");

    do {
        count++;
        f0 = (*fun)(x0);
        df0 = (*dfun)(x0);
        x1 = x0 - (f0 / df0);
        printf("\n%d\t %.3f\t %.3f\t %.3f\t %.3f", count, x0, x1, f0, df0);
        x0 = x1;
    } while (fabs(f0 / df0) > E);

    printf("\nRoot = %.3f\n", x1);
}

int main() {
    float x0;

    printf("\nEnter a number for fun1: ");
    scanf("%f", &x0);
    ROOT(x0, fun1, dfun1);

    printf("\nEnter a number for fun2: ");
    scanf("%f", &x0);
    ROOT(x0, fun2, dfun2);

    return 0;
}
