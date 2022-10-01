# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(void) {
	int M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);

	for (int i = 0; i < F1 || i < F2; i++) {
		if (i < F1) {
			if (i % (N1 + E1) < N1)
				Y1 = (Y1 + 1) % N;
			else
				X1 = (X1 + 1) % M;
		}
		if (i < F2) {
			if (i % (N2 + E2) < E2)
				X2 = (X2 + 1) % M;
			else
				Y2 = (Y2 + 1) % N;
		}
		if (X1 == X2 && Y1 == Y2) {
			printf("robots explode at time %d\n", i + 1);
			return 0;
		}
	}
	printf("robots will not explode\n");
	return 0;
}

