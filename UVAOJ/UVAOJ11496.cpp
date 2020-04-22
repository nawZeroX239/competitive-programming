#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int n;
	int a[10002];
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int peak = 0;
		int state = 0;
		a[n] = a[0];
		a[n + 1] = a[1];
		for(int i=1; i<=n+1; i++)
			if (a[i] > a[i - 1]) {
				if (state == -1)
					peak++;

				state = 1;
			} else if (a[i] < a[i - 1]) {
				if (state == 1)
					peak++;

				state = -1;
			}

		printf("%d\n", peak);
	}
	return 0;
}
