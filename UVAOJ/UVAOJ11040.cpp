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

int wall[10][10];
int n = 5;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int c1, c2, x;
	vector<int> v, temp;
	scanf("%d", &t);
	while (t) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j/2 <= i; j += 2)
				scanf("%d", &wall[i][j]);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j/2 < i; j += 2) {
				c1 = wall[i][j];
				c2 = wall[i][j + 2];
				x = (wall[i - 1][j] - c1 - c2) / 2;
				wall[i][j + 1] = x;
				// printf("x %d ", x);
			}
			// printf("\n");
		}

		printf("%d\n", wall[0][0]);
		for (int i = 1, k=3; i < n; i++, k+=2) {
			printf("%d", wall[i][0] + wall[i][1]);
			for (int j = 1; j < k-1; ++j)
				printf(" %d", wall[i][j] +wall[i][j+1]);
			printf("\n");
			printf("%d", wall[i][0]);
			for (int j = 1; j < k; ++j)
				printf(" %d", wall[i][j]);
			printf("\n");
		}
		--t;
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