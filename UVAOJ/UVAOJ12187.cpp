#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;
template<typename T> void get_num(T&);

int a[101][101], b[101][101];

int N, R, C, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	while (scanf("%d%d%d%d", &N, &R, &C, &K)) {
		if (N == 0 && R == 0 && C == 0 && K == 0)
			break;
		for (i = 0; i < R; ++i)
			for (j = 0; j < C; ++j)
				scanf("%d", &a[i][j]);
		for (i = 0; i < R; ++i)
			for (j = 0; j < C; ++j)
				b[i][j]=-1;
		while (K) {
			for(i=0; i<R; ++i)
				for (j = 0; j < C; ++j) {
					// b[i][j] = a[i][j];
					//printf("(a[i][j]+1)%%N %d \n", (a[i][j] + 1) % N);

					if (i + 1 < R &&  (a[i][j] + 1)%N== a[i + 1][j]) {
						b[i + 1][j] = a[i][j];
					}
					if (i - 1 >= 0 && (a[i][j] + 1) % N == a[i - 1][j]) {
						b[i - 1][j] = a[i][j];
					}

					if (j + 1 < C && (a[i][j] + 1) % N == a[i][j + 1]) {
						b[i][j + 1] = a[i][j];
					}

					if (j - 1 >= 0 && (a[i][j] + 1) % N == a[i][j - 1]) {
						b[i][j - 1] = a[i][j];
					}
				}

			for (i = 0; i < R; ++i)
				for (j = 0; j < C; ++j)
					if(b[i][j] != -1)
						a[i][j] = b[i][j];
			--K;
		}

		for (i = 0; i < R; ++i) {
			printf("%d", a[i][0]);
			for (j = 1; j < C; ++j)
				printf(" %d", a[i][j]);
			printf("\n");
		}

	}
	return 0;
}



template<typename T> void get_num(T& num) {
	int sign = 1;
	register int c;
	num = 0;

	while (true) {
		c = getchar();
		if (c >= '0' && c <= '9')
			break;

		if (c == '-') {
			c = getchar();
			if (c >= '0' && c <= '9') {
				sign = -1;
				break;
			}
		}

	}


	for (; c >= '0' && c <= '9'; c = getchar())
		num = num * 10 + c - 48;

	num = num * sign;
}