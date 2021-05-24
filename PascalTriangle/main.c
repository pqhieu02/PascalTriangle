#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calculate(int n, int *triangle) {
	int side[100];
	side[0] = 1;
	for (int i = 1; i < n - 1; i++) {
		side[i] = triangle[i] + triangle[i - 1];
	}
	side[n - 1] = 1;
	for (int i = 0; i < n; i++) {
		triangle[i] = side[i];
	}
}

void render(int n, int *triangle, int botside) {
	if (n > 2) {
		calculate(n, triangle);
	}
	for (int space = 0; space < (botside - n) * 5; space++) {
		printf(" ");
	}
	for (int i = 0; i < n; i++) {
		printf("%9d ", triangle[i]);
	}
	printf("\n");
}

void main() {
	int n, triangle[100] = { 0 };
	triangle[0] = 1;
	triangle[1] = 1;
	printf("Enter a number: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		render(i, triangle, n);
	}
}