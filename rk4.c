// rk4 method
#include <stdio.h>
float fun(float x) {
    return 1 + 3 * x * x;
}

int main() {
    int i, n;
    float x, y, h, xp, m1, m2, m3, m4;
    printf("\nEnter the initial values x, y and stepsize h: ");
    scanf("%f%f%f", &x, &y, &h);
    printf("\nEnter xp: ");
    scanf("%f", &xp);
    n = (xp - x) / h;
    for(i = 0; i < n; i++) {
        m1 = fun(x);
        m2 = fun(x+h/2);
        m3 = fun(x+h/2);
        m4 = fun(x+h);
        y += h * ( m1 + 2 * m2 + 2 * m3 + m4 ) / 6;
        x += h;
    }

    printf("\nResult: x = %f \t y = %f", x, y);
    return 0;
}
