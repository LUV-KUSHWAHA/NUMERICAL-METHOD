#include <stdio.h>
#include <math.h>

float fun1(float x) {
    return x * x - 4 * x - 10;
}

float fun2(float x) {
    return 4 * sin(x) - exp(x);
}

void ROOT(float x0, float x1, float (*fun)(float)) {
    int count = 0;
    float x2, f0, f1, E = 0.0001;
    do {
        count++;
        f0 = (*fun)(x0); // Correct usage of function pointer
        f1 = (*fun)(x1); // Correct usage of function pointer
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        x0 = x1;
        x1 = x2;
        printf("\n%d x0 = %f", count, x0);
    } while (fabs((x1 - x0) / x1) > E);
    printf("\nRoot = %.3f\n", x2);
}

int main() {
    float x0, x1;

    printf("\nEnter two numbers for fun1: ");
    scanf("%f %f", &x0, &x1);
    ROOT(x0, x1, fun1);

    printf("\nEnter two numbers for fun2: ");
    scanf("%f %f", &x0, &x1);
    ROOT(x0, x1, fun2);

    return 0;
}
