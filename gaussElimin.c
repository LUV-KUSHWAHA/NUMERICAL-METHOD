// GAUSSS ELIMINATION METHOD TO SOLVE SYSTEM OF LINEAR EQUATIONS
#include <stdio.h>

int main() {
    int i, j, k, n = 3;
    float a[3][4], x[3], ratio;

    // Input augmented matrix
    printf("\nEnter the augmented matrix (3x4): ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gaussian elimination
    for (i = 0; i < n - 1; i++) {
        if (a[i][i] == 0) {
            printf("\nMathematical error: Division by zero\n");
            return -1;
        }
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = i; k < n + 1; k++) {
                a[j][k] -= a[i][k] * ratio;
            }
        }
    }

    // Back substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1]; // Last variable
    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n]; // Start with the constant term
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j]; // Subtract the known values
        }
        x[i] /= a[i][i]; // Divide by the diagonal coefficient
    }

    // Output the solution
    printf("\nThe solutions are:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, x[i]);
    }

    return 0;
}
