#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int n, m, lastcall = 0;
	scanf("%d%d", &n, &m);
	int x[n][m * m + 1], y[n][m * m + 1];
	bool B[n][m][m];
	char name[n][65];
	bool win[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			B[n][i][j] = false;
	for (int k = 0; k < n; k++) {
		scanf("%s", &name[k]);
		int a;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &a);
				x[k][a] = i;
				y[k][a] = j;
			}
	}
	for (int k = 0; k < n; k++)
		win[k] = false;

	int call = 1;
	while (scanf("%d", &call) != EOF) {

		for (int k = 0; k < n; k++) {

			bool b;
			B[k][x[k][call]][y[k][call]] = true;
			for (int i = 0; i < m && !(win[k]); i++) {
				b = true;
				for (int j = 0; j < m; j++)//check r
					if (!(B[k][i][j]))
						b = false;
				if (b) {
					lastcall = call;
					win[k] = true;
				}
				b = true;
				for (int j = 0; j < m && !(win[k]); j++)//check c
					if (!(B[k][j][i]))
						b = false;
				if (b) {
					lastcall = call;
					win[k] = true;
				}
			}
			if (!(win[k])) {
				b = true;
				int xd = 0, yd = 0;
				for (int i = 0; i < m; i++) {//check diagnal
					if (!(B[k][xd][yd]))
						b = false;
					else {
						xd++;
						yd++;
					}
				}
				if (b) {
					lastcall = call;
					win[k] = true;
				}
				b = true;
				xd = m - 1;
				yd = 0;
				for (int i = 0; i < m && !(win[k]); i++) {//check another diagnal
					if (!(B[k][xd][yd]))
						b = false;
					else {
						xd--;
						yd++;
					}
				}
				if (b) {
					lastcall = call;
					win[k] = true;
				}
			}
		}
		if (lastcall == call)
			break;
	}

	printf("%d", lastcall);
	for (int k = 0; k < n; k++)
		if (win[k])
			printf(" %s", name[k]);
}

