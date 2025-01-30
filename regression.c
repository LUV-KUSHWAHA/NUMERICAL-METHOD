// linear regression using least square regression method
#include <stdio.h>
#define SIZE 20  // Uppercase for constants by convention

int main() {
    int n, i;
    float a, b, w, p;
    float x[SIZE], y[SIZE];
    float sumx = 0, sumxx = 0, sumy = 0, sumxy = 0;

    // Input number of data points
    printf("\nEnter the number of data points: ");
    scanf("%d", &n);

    // Input (x, y) pairs
    for (i = 0; i < n; i++) {
        printf("\nEnter x[%d] and y[%d]: ", i + 1, i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Compute sums
    for (i = 0; i < n; i++) {
        sumxx += x[i] * x[i];
        sumx += x[i];
        sumxy += x[i] * y[i];
        sumy += y[i];
    }

    // Check for division by zero
    float denominator = (n * sumxx - sumx * sumx);
    if (denominator == 0) {
        printf("\nError: Division by zero. Cannot compute linear regression.\n");
        return 1;
    }

    // Compute regression coefficients
    b = (n * sumxy - sumx * sumy) / denominator;
    a = (sumy - b * sumx) / n;

    // Print the regression equation
    printf("\nThe linear regression equation is: y = %.2f + %.2fx\n", a, b);

    // Predict values for given w until user exits
    while (1) {
        printf("\nEnter value of w (or -999 to exit): ");
        scanf("%f", &w);
        if (w == -999) break;  // Exit condition
        p = a + b * w;
        printf("Predicted value: p = %.2f\n", p);
    }

    return 0;
}
