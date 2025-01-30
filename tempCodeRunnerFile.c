#include <stdio.h>
#define size 20

int main()
{
    int n, i;
    float x[size], y[size];
    float sumx = 0, sumxx = 0, sumy = 0, sumxy = 0;
    float a, b, xp, yp;

    printf("\nEnter the no. of data points: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("\nEnter y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    for(i = 0; i < n; i++)
    {
        sumxx += (x[i] * x[i]);
        sumx += x[i];
        sumxy += (x[i] * y[i]);
        sumy += y[i];
    }

    b = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
    a = (sumy - b * sumx) / n;

    printf("\na = %f\nb = %f", a, b);

    printf("\nEnter xp: ");
    scanf("%f", &xp);

    yp = a + b * xp; // Correct formula for linear regression
    printf("\ny(%f) = %f", xp, yp);

    return 0;
}
