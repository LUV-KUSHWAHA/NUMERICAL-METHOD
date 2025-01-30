#include <stdio.h>
#define size 20

int main()
{
    int n, i, j;
    float x[size], a[size][size], l[size], xp, p;
    printf("\nEnter the degree of the polynomial: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter x[%d]: ",i);
        scanf("%f",&x[i]);
        printf("\nEnter a[0][%d]: ",i);
        scanf("%f",&a[0][i]);
    }
    while(1)
    {
        printf("\nEnter interpolation value xp: ");
        scanf("%f",&xp);
        for(i = 1; i < n; i++)
        {
            for(j = 0; j < n - i; j++)
            {
                a[i][j] = (a[i-1][j+1] - a[i-1][j]) / (x[i+j] - x[j]);
            }
        }

        p = a[0][0];
        for(i = 1; i < n; i++)
        {
            l[i] = 1;
            for(j = 0; j < i; j++) // Corrected this line
            {
                l[i] *= (xp - x[j]);
            }
            p += (a[i][0] * l[i]);
        }
        printf("\nP = %.2f", p);
    }
    return 0;
}
