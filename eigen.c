// PROGRAM TO FIND LARGEST EIGEN VALUES AND EIGEN VECTOR
#include <stdio.h>
#include <math.h>

int main() 
{
    int i, j, n, count = 0;
    float e = 0. 01, lambda_old = 1, lambda_new, x_new[50], x_old[50];
    float a[50][50], temp;

    // Input for matrix order and tolerable error
    printf("\nEnter the order n (dimension of matrix): ");
    scanf("%d", &n);

    // Input for matrix A (n x n)
    printf("\nEnter the matrix (%dx%d): \n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Input for initial guess vector (n x 1)
    printf("\nEnter the initial guess vector (%dx1): \n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &x_old[i]);
    }

    // Power Method iteration
    do {
        // Matrix-vector multiplication: x_new = A * x_old
        for (i = 0; i < n; i++) {
            x_new[i] = 0;
            for (j = 0; j < n; j++) {
                x_new[i] += a[i][j] * x_old[j];
            }
        }

        // Find the maximum value in x_new as the new eigenvalue (lambda_new)
        lambda_new = fabs(x_new[0]);
        for (i = 1; i < n; i++) {
            if (fabs(x_new[i]) > lambda_new) {
                lambda_new = fabs(x_new[i]);
            }
        }

        // Normalize the new vector
        for (i = 0; i < n; i++) {
            x_new[i] /= lambda_new;
        }

        // Check for convergence
        temp = fabs(lambda_new - lambda_old);
        lambda_old = lambda_new;

        // Update x_old with x_new for the next iteration
        for (i = 0; i < n; i++) {
            x_old[i] = x_new[i];
        }

        count++;
    } while (temp > e);

    // Print the results
    printf("\nThe dominant eigenvalue is: %f\n", lambda_new);
    printf("The corresponding eigenvector is:\n");
    for (i = 0; i < n; i++) {
        printf("%f\n", x_new[i]);
    }
    printf("Number of iterations: %d\n", count);

    return 0;
}
