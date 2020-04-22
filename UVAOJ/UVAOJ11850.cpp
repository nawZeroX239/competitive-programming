#include <cstdio>
#include <algorithm> 

using namespace std;

int main() {
	int n;
	int a[1450];
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		bool b = true;
		sort(a, a + n);
		int mile=200;
		for (int i = 1; i < n && b; i++)
			if (a[i] - a[i - 1] > mile)
				b = false;

		if (1422-a[n - 1]>100) {
			// make sure we have enough gas for around trip from last gas station to last mile
			b = false;
		}

		if (b) {
			printf("POSSIBLE\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
