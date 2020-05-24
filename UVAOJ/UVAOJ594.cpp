#include <iostream>
#include <string>

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;
	int N = 32;
	int bits[32];

	while (scanf("%d", &n) > 0) {
		int m = 0;
		for (int i = 0; i < N; i++) {
			bits[i] = (1 << i & n) && 1;
		}

		//for (int i = 0; i < N; i++)
		//	cout << bits[i] << " ";
		//cout << endl;

		for (int i = 0, l=N, k=0; i < 4; i++) {
			l -= 8;
			for (int j = 0; j < 8; j++, k++) {
				m = m | (int)pow(2, l+j) * bits[k];
			}
		}
		printf("%d converts to %d\n", n, m);
	}
	return 0;
}