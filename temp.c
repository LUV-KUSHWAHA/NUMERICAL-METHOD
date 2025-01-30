#include <stdio.h>
#define size 20

void gaussElimination(float a[3][4], float var[3]);

int main()
{
    int n = 5, i;
    float x[size] = {0, 1, 2, 3, 4}, y[size] = {1.0, 1.8, 1.3, 2.5, 6.3}, var[3];
    float a, b, c, xp = 1, yp;
    float Ex = 0, Ex2 = 0, Ex3 = 0, Ex4 = 0, Ey = 0, Exy = 0, Ex2y = 0;

    for(i = 0; i < n; i++)
    {
        Ex += x[i];
        Ex2 += x[i] * x[i];
        Ex3 += x[i] * x[i] * x[i];
        Ex4 += x[i] * x[i] * x[i] * x[i];
        Ey += y[i];
        Exy += x[i] * y[i];
        Ex2y += x[i] * x[i] * y[i];
    }

    float A[3][4] = { {n, Ex, Ex2, Ey}, {Ex, Ex2, Ex3, Exy}, {Ex2, Ex3, Ex4, Ex2y} }; 
    gaussElimination(A, var);
    a = var[0];
    b = var[1];
    c = var[2];

    yp = a * xp * xp + b * xp + c;
    printf("\ny(%f) = %f\n", xp, yp);

    return 0;
}

void gaussElimination(float a[3][4], float var[3]) 
{
    int i, j, k;
    float temp, term;
    for (i = 0; i < 3; i++) {
        // Partial Pivoting
        for (k = i + 1; k < 3; k++) {
            if (a[i][i] < a[k][i]) {
                for (j = 0; j <= 3; j++) {
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
        // Forward Elimination
        for (k = i + 1; k < 3; k++) 
        {
            term = a[k][i] / a[i][i];
            for (j = 0; j <= 3; j++) {
                a[k][j] -= term * a[i][j];
            }
        }
    }
    // Back Substitution
    for (i = 2; i >= 0; i--) 
    {
        var[i] = a[i][3];
        for (j = i + 1; j < 3; j++) 
        {
            var[i] -= a[i][j] * var[j];
        }
        var[i] /= a[i][i];
    }
}
