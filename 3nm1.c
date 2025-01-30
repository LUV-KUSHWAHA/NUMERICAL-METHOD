#include <stdio.h>
#define size 20

int main()
{
    int n, i, j;
    float x[size], f[size], l[size], xp, p ;
    printf("\nEnter the degree of the polynomial: ");
    scanf("%d",&n);
    for(i = 0 ; i<n ; i++)
    {
        printf("\nEnter x[%d]: ",i);
        scanf("%f",&x[i]);
        printf("\nEnter f[%d]: ",i);
        scanf("%f",&f[i]);
    }
    while(1)
    {
    	p = 0;
        printf("\nEnter interpolation value xp: ");
        scanf("%f",&xp);
        for(i=0;i<n;i++)
        {
            l[i] = 1;
            for(j=0;j<n;j++)
            {
                if(i != j)
                {
                    l[i] *= ((xp - x[j])/(x[i]-x[j]));
                }
            }
            p += ( f[i] * l[i] );
        }
        printf("\nP = %.2f",p);
    }
    return 0;
}
