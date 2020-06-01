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

int a[10][10], b[10][10], ans[10][10];
int front[10], side[10];
int N;

void debug(int m[][10]) {
	puts("");
	for (int i = 0; i < N; ++i) {
		printf("%d", m[i][0]);
		for (int j = 1; j < N; ++j)
			printf(" %d", m[i][j]);
		puts("");
	}
	puts("");
}

int main() {
	int g, h;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T) {
		scanf("%d", &N);
		for (int i = 0; i<N; ++i)
			scanf("%d", &front[i]);

		for (int i = 0; i < N; ++i)
			scanf("%d", &side[i]);

		g = h = 0;
		for(int i=0; i<N; ++i)
			for (int j = 0; j < N; ++j) {
				a[i][j] = front[i];
				b[i][j] = side[j];
			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				ans[i][j] = min(a[i][j], b[i][j]);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				g += ans[i][j];
		for (int i = 0; i < N; ++i) {
			h = h + front[i];
			for(int j=0; j<N; ++j)
				if (front[i] == side[j]) {
					side[j] = 0;
					break;
				}

		}

		for (int i = 0; i < N; ++i)
			h = h + side[i];
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", h, g-h);

		--T;
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