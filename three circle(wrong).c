# define _CRT_SECURE_NO_WARNINGS
# define num 3
# define R 10
# define L 21
#include <stdio.h>
#include <stdbool.h>

void setdots(int* xptr, int* yptr, int r, int* dotptr) { // Actually, yptr is deletable, and checkdots is, too
	int x0 = *xptr;
	int y0 = *yptr;

	for (int i = -r; i <= r; i++)
		for (int j = -r; j <= r; j++) {
			*(xptr + 2 * i) = x0 + i;
			*(yptr + 2 * j) = y0 + j;
			if (i * i + j * j <= r * r) {
				(* (dotptr + i * L + j))++;
			}
		}
}

void checkdots(int* x1ptr, int* y1ptr, int r1, int* x2ptr, int* y2ptr, int r2, int* dotptr1, int* dotptr2) {// delete the second true dot

	for (int i1 = -r1; i1 <= r1; i1++)
		for (int i2 = -r2; i2 <= r2; i2++)
			for (int j1 = -r1; j1 <= r1; j1++)
				for (int j2 = -r2; j2 <= r2; j2++){
					if (*(y2ptr + 2 * j2) == 0 && *(x2ptr + 2 * i2) == -1)
						printf("                              %d  %d\n", *(x1ptr + 2 * i1), *(y1ptr + 2 * j1));
					if (*(x1ptr + 2 * i1) == *(x2ptr + 2 * i2) && *(y1ptr + 2 * j1) == *(y2ptr + 2 * j2) && *(dotptr1 + i1 * L + j1) > 0 && *(dotptr2 + i2 * L + j2) > 0) {
						(* (dotptr1 + i1 * L + j1))++;
						(* (dotptr2 + i2 * L + j2))++;
						printf("%d        %d\n", * (x1ptr + 2 * i1) ,* (y1ptr + 2 * j1));
					}
				}
}

int main(void) {
	int n, adr[num][L][2], r[num];
	for (scanf("%d", &n); n > 0; n--) {
		int sum = 0;
		int dot[num][L][L] = { 0 };
		
		for (int i = 0; i < num; i++) {
			scanf("%d%d%d", &adr[i][R][0], &adr[i][R][1], &r[i]);
			setdots(&adr[i][R][0], &adr[i][R][1], r[i], &dot[i][R][R]);
		}

		checkdots(
			&adr[0][R][0], &adr[0][R][1], r[0], 
			&adr[1][R][0], &adr[1][R][1], r[1], 
			&dot[0][R][R], &dot[1][R][R]);
		checkdots(
			&adr[1][R][0], &adr[1][R][1], r[1],
			&adr[2][R][0], &adr[2][R][1], r[2],
			&dot[1][R][R], &dot[2][R][R]);
		checkdots(
			&adr[2][R][0], &adr[2][R][1], r[2],
			&adr[0][R][0], &adr[0][R][1], r[0],
			&dot[2][R][R], &dot[0][R][R]);

		int a = 0;
		for (int j = 0; j < num; j++)
			for (int k = 0; k < L; k++)
				for (int l = 0; l < L; l++) {
					if (dot[j][k][l] == 1){
						sum++;
					}
					if (dot[j][k][l] == 3) {
						sum++;
						a++;
					}
				}

		printf("%d\n", (sum - (a * 2 / 3)));
	}
}