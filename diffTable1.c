// Newton's Forward Difference Table of interpolation
#include <stdio.h>
#define SIZE 20  // Uppercase for constants by convention

int main() {
    int n, i, j;
    float x[SIZE], y[SIZE][SIZE] = {0};  // Initialize y array to 0

    // Input for number of data points
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    // Input x values and compute y[0][i] = f(x[i])
    printf("\nEnter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        y[0][i] = x[i] * x[i] + 2;  // Function: f(x) = x² + 2
    }

    // Compute forward differences
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[j][i] = y[j - 1][i + 1] - y[j - 1][i];
        }
    }

    // Print the Forward Difference Table
    printf("\nForward Difference Table:\n");
    printf("x\tf(x)\t");
    for (j = 1; j < n; j++) {
        printf("Δ^%d\t", j);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);  // Print x values
        for (j = 0; j < n - i; j++) {
            printf("%.2f\t", y[j][i]);
        }
        printf("\n");
    }

    return 0;
}
