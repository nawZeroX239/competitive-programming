#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main() {
	int n;
	int c[101];
	int d[101];
	int N, K, L;
	char u;
	string str;
	scanf("%d", &n);
	getline(cin, str);
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		scanf("%d%d", &N, &K);
		getline(cin, str);
		memset(c+1, -1, sizeof(int)*N);

		for (int k = 0; k < K; k++) {
			scanf("%d", &L);
			for (int l = 0; l < L*2; l+=2) {
				scanf("%d%d", &d[l], &d[l+1]);
			}
			getline(cin, str);
			scanf("%c", &u);
			getline(cin, str);
			if (u == '=') {
				for (int l = 0; l < L * 2; l += 2) {
					c[d[l]] = 1;
					c[d[l + 1]] = 1;
				}
			}
		}
//		for (int k = 1; k <= N; k++)
//			printf("%d ", c[k]);
		int minus = 0;
		int idx = -1;
		for (int k= 1; k <= N && minus<2; k++)
			if (c[k] == -1) {
				if (idx == -1)
					idx = k;
				minus++;
			}

		if (minus<2) {
			printf("%d\n", idx);
		} else {
			printf("0\n");
		}

		if (i + 1 < n)
			printf("\n");
	}
	return 0;
}
