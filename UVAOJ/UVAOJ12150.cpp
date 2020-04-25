#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
	int n;
	int cars[1001];
	long sum = 0;
	int c, s;
	bool b;
	unordered_set<int> uset;
	while (scanf("%d", &n) && n > 0) {
		sum = 0;
		b = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &c, &s);
			//printf(" i+s:%d ", i + s);
			sum += s;
			if (!b)
				continue;

			if (i+s<1 || i+s>n || (i + s > 0 && i + s < n+1 
				&& uset.find(i + s) != uset.end())) {
				b = false;
			} else {
				uset.insert(i + s);
				cars[i + s] = c;
			}

		}
		//printf(" sum:%d ", sum);
		if (sum != 0 || !b) {
			printf("%d\n", -1);
		} else {
			printf("%d", cars[1]);
			for (int i = 2; i < n + 1; i++)
				printf(" %d", cars[i]);
			printf("\n");
		}

		uset.clear();
	}
	return 0;
}
