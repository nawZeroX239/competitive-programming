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

int grid[101][101];
int a[101], b[101], c[101], d[101];
int M, N, T, C;

void debug() {
	puts("");
	for (int i = 0; i < N; ++i) {
		printf("%d", grid[i][0]);
		for (int j = 1; j < N; ++j)
			printf(" %d", grid[i][j]);
		puts("");
	}
	puts("");
}

void debug(int a[], int len) {
	printf("%d", a[0]);
	for (int i = 1; i < len; ++i)
		printf(" %d", a[i]);

	puts("");
}

void copy(int i, int j, int len) {
	for (int l = 0; l < len; ++l) {
		a[l] = grid[i][j + l];
		b[l] = grid[i + len - 1][j + l];
		c[l] = grid[i + l][j];
		d[l] = grid[i + l][j + len - 1];
	}
}

void upside_down(int i, int j, int len) {

	for (int l = 0; l < len; ++l) {
		grid[i][j + l] = b[l];
		grid[i + len - 1][j + l] = a[l];
		grid[i + l][j] = c[len - 1 - l];
		grid[i + l][j + len - 1] = d[len - l - 1];
	}
}

void left_right(int i, int j, int len) {
	for (int l = 0; l < len; ++l) {
		grid[i][j + len - 1 - l] = a[l];
		grid[i + len - 1][j + len - 1 - l] = b[l];
		grid[i + l][j] = d[l];
		grid[i + l][j + len - 1] = c[l];
	}
}

void main_diagonal(int i, int j, int len) {
	for (int l = 0; l < len; ++l) {
		grid[i][j + l] = c[l];
		grid[i + l][j + len - 1] = b[l];
		grid[i + len - 1][j + l] = d[l];
		grid[i + l][j] = a[l];

	}
}

void inverse_diagonal(int i, int j, int len) {
	for (int l = 0; l < len; ++l) {
		grid[i][j + l] = d[len-l-1];
		grid[i + l][j + len - 1] = a[len - l - 1];
		grid[i + len - 1][j + l] = c[len - l - 1];
		grid[i + l][j] = b[len - l - 1];
		
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	scanf("%d", &M);
	while (M) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
				scanf("%d", &grid[i][j]);

		T = (N & 1 ? N/2+1 : N/2); // number of ring
		

		for (k = 0, m = N; T; --T, ++k, m -= 2) {
			scanf("%d", &C);
			// printf("T %d N %d C %d\n", T, N, C);
			while (C) {
				scanf("%d", &l);
				copy(k, k, m);
				if (l == 1) {
					upside_down(k, k, m);
				} else if (l == 2) {
					left_right(k, k, m);
				} else if (l == 3) {
					main_diagonal(k, k, m);
				} else {
					inverse_diagonal(k, k, m);
				}
				--C;
			}
		}
		// debug();
		for (i = 0; i < N; ++i) {
			printf("%d", grid[i][0]);
			for (j = 1; j < N; ++j)
				printf(" %d", grid[i][j]);
			puts("");
		}
		--M;
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