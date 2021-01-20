#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,k,L,deg,check_saturation;

    deg=3;

    printf("input L = ");
    scanf("%d", &L);
    int N;

    N = 2*L ;

    int A[N][deg];
    double V[N],prev_V[N], I, sumI;
    double R[N][deg];

    A[0][0] = L-1, A[0][1] = 1, A[0][2] = L;
    A[L-1][0] = L-2, A[L-1][1] = 0, A[L-1][2] = N-1;
    A[L][0] = 0, A[L][1] = L+1, A[L][2] = N-1;
    A[N-1][0] = N-2, A[N-1][1] = L, A[N-1][2] = L-1;

    printf("input L = ");

    for(i=1;i<L-1;i++)
    {
        A[i][0] = i-1;
        A[i][1] = i+1;
        A[i][2] = L+i;
    }

    for(i=L+1;i<N-1;i++)
    {
        A[i][0] = i-1;
        A[i][1] = i+1;
        A[i][2] = i-L;
    }

    R[0][0]=3.0, R[0][1]= 2.0, R[0][2]=2.0;
    R[L-1][0]=2.0, R[L-1][1] = 3.0, R[L-1][2]=2.0;
    R[L][0]= 2.0, R[L][1]=2.0, R[L][2]=3.0;
    R[N-1][0]=2.0, R[N-1][1]=3.0, R[N-1][2]=2.0;

    for(i=1;i<L-1;i++)
    {
        R[i][0]= 2.0;
        R[i][1]= 2.0;
        R[i][2]= 2.0;
    }

    for(i=L+1;i<N-1;i++)
    {
        R[i][0]=2.0;
        R[i][1]=2.0;
        R[i][2]=2.0;
    }

    V[0] = 1, V[N-1] = 0;


    for(i=1; i<N-1; i++)
    {
        V[i] = 1.0;
        prev_V[i] = 1.0;
    }

    double numerator, denominator;


    while(1)
    {
        for(i=1;i<N-1; i++)
        {
            numerator = 0;
            denominator = 0;
            for(k=0; k<deg; k++)
            {
                numerator = numerator + V[A[i][k]]/R[i][k];
                denominator = denominator + 1.0/R[i][k];

            }

            V[i] = numerator/denominator;
        }

        check_saturation = 0;

        for(i=1;i<N-1; i++)
        {
            if(fabs(V[i]-prev_V[i])>1e-8)
                check_saturation = 1;
        }

        if(check_saturation == 0)
            break;

        for(i=1; i<N-1; i++)
            prev_V[i] = V[i];
    }

    for(i=0; i<N; i++)
        printf("V[%d] = %f\n", i, V[i]);

    for(j=0;j<3; j++)
        printf("0 to %d : %f\n", A[0][j], (V[A[0][j]]-V[0]));

    for(j=0; j<3; j++)
        printf("%d to %d : %f\n", A[N-1][j], N-1, (-V[A[N-1][j]]+V[N-1]));

    I=0;

    for(j=0;j<3;j++)
    {
        I = I + V[A[N-1][j]]-V[N-1];
    }

    sumI = I;

    printf("composite resistance between 0 to %d : %f\n", N-1, 1/sumI );

    return 0;
}

