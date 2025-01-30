// Newton's backward difference table
#include <stdio.h>
#define SIZE 20  // Use uppercase for constants by convention

int main() {
    int n, i, j;
    float x[SIZE], y[SIZE][SIZE] = {0};  // Initialize y array to 0

    // Input for number of data points
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    // Input x values
    printf("\nEnter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        y[i][0] = x[i] * x[i] * x[i] - 1;  // Compute y values
    }

    // Compute backward differences
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Print the Backward Difference Table
    printf("\nBackward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);  // Print x values
        for (j = 0; j <= i; j++) {
            printf("%.2f\t", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}
