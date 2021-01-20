#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	int i, j, k, N, L, deg, check_saturation;

	deg=3;
	printf ("Input L:");
	scanf ("%d", &L);
	N=2 * L;

	int A[N][deg];
	double R[N][deg], numerator, denominator;
	double V[N], prev_V[N];

	A[0][0]=1, A[0][1]=L - 1, A[0][2]=L;
	A[L - 1][0]=0, A[L - 1][1]=L - 2, A[L - 1][2]=2 * L - 1;
	A[L][0]=0, A[L][1]=L + 1, A[L][2]=2 * L - 1;
	A[2 * L - 1][0]=L - 1, A[2 * L - 1][1]=L, A[2 * L - 1][2]=2 * L - 2;

	for (i=1; i < L - 1; i++)
		A[i][0]=i - 1, A[i][1]=i + 1, A[i][2]=i + L;
	for (i=L + 1; i < 2 * L - 1; i++)
		A[i][0]=i - L, A[i][1]=i - 1, A[i][2]=i + 1;

	for (i=0; i < N; i++) {
		for (j=0; j < deg; j++)
			R[i][j]=1;
	}

	V[0]=1, V[N - 1]=0;

	for (i=1; i < N - 1; i++) {
		V[i]=1.0;
		prev_V[i]=1.0;
	}

	while (1) {
		for (i=1; i < N - 1; i++) {
			numerator=0;
			denominator=0;
			for (k=0; k < deg; k++) {
				numerator=numerator + V[A[i][k]] / R[i][k];
				denominator=denominator + 1.0 / R[i][k];
			}

			V[i]=numerator / denominator;
		}

		check_saturation=0;

		for (i=1; i < N - 1; i++) {
			if (fabs (V[i] - prev_V[i]) > 1e-8)
				check_saturation=1;
		}

		if (check_saturation == 0)
			break;

		for (i=1; i < N - 1; i++) {
			prev_V[i]=V[i];
		}
	}

	for (i=0; i < N; i++) {
		printf ("V[%d]=%f\n", i, V[i]);
	}

	double sum_current=0;

	for (i=0; i < deg; i++) {
		printf ("%d to %d : %f\n", 0, A[0][i], (V[0] - V[A[0][i]]) / R[0][i]);
		sum_current+=(V[0] - V[A[0][i]]) / R[0][i];
	}

	for (i=0; i < deg; i++)
		printf ("%d to %d : %f\n", A[N - 1][i], N - 1, (V[A[N - 1][i]] - V[N - 1]) / R[N - 1][i]);

	printf ("composite resistance between 0 and %d: %f\n", N - 1, 1.0 / sum_current);

	return 0;
}
