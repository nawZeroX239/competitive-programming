#include <cstdio>
#include <algorithm> 

using namespace std;

int main() {
	int a[13];
	int Case = 1;
	int b;
	while (scanf("%d", &a[0]) && a[0]>-1) {
		for (int i = 1; i <= 12; i++)
			scanf("%d", &a[i]);
		printf("Case %d:\n", Case++);
		for (int i = 1; i <= 12; i++) {
			scanf("%d", &b);
			if (a[i - 1] >= b) {
				a[i] = a[i] + a[i - 1] - b;
				printf("No problem! :D\n");
			} else {
				a[i] = a[i] + a[i - 1];
				printf("No problem. :(\n");
			}
		}
	}
	return 0;
}
