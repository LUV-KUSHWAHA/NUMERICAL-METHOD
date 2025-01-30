// euler's method
#include <stdio.h>
float fun(float x) {
    return 1 + 3 * x * x;
}

int main() {
    int i, n;
    float x, y, h, xp, f;

    printf("\nEnter the initial values x, y and stepsize h: ");
    scanf("%f%f%f", &x, &y, &h);
    printf("\nEnter xp: ");
    scanf("%f", &xp);

    n = (xp - x) / h;
    for(i = 0; i < n; i++) {
        f = fun(x);
        y += h * f;
        x += h;
    }

    printf("\nResult: x = %f \t y = %f", x, y);
    return 0;
}
