#include <stdio.h>
#include <malloc.h>
#include <cstring>

int main() {
	int S, B, L, R;
	int right[100002];
	int left[100002];
	while (true) {
		scanf("%d%d", &S, &B);
		if (S == 0 && B == 0)
			break;

		for (int i = 1; i <= S; i++) {
			left[i] = i - 1; // i's left soldier
			right[i] = i + 1;// i's right soldier
		}
		right[S] = 0;
		for (int i = 0; i < B; i++) {
			scanf("%d%d", &L, &R);
			left[right[R]] = left[L]; // new left is left of new right and is left of old left
			if (left[L] > 0)
				printf("%d", left[L]);
			else
				printf("*");
			right[left[L]] = right[R]; // same for right
			printf(" ");
			if (right[R] > 0)
				printf("%d", right[R]);
			else
				printf("*");
			printf("\n");
		}
		printf("-\n");
	}

	return 0;
}