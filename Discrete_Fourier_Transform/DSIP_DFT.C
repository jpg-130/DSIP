#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
	double ans[50][2];
	int x[50];
	int N, k, i;
	double u, v;
	clrscr();

	printf("Enter the value of the period: ");
	scanf("%d", &N);
	printf("Enter the values of the signal\n");
	for (i = 0; i < N; i++)
		scanf("%d", &x[i]);

	for (k = 0; k < N; k++) {
		u = 0.0;
		v = 0.0;
		for (i = 0; i < N; i++) {
			u += x[i] * cos(-(2 * M_PI * i * k) / N);
			v += x[i] * sin(-(2 * M_PI * i * k) / N);
		}
		ans[k][0] = u;
		ans[k][1] = v;
	}

	for (k = 0; k < N; k++) {
		u = sqrt(ans[k][0]*ans[k][0] + ans[k][1]*ans[k][1]);
		if (abs(ans[k][0] - 0.0) < 0.01)
			v = 1.0;
		else
			v = atan(ans[k][1] / ans[k][0]);
		printf("K = %d --> (%.2lf + j(%.2lf)) %.2lf <%.2lf>\n", k, ans[k][0], ans[k][1], u, v);
	}

	getch();
	return 0;
}
