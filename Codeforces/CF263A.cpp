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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string line;
	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	int matrix[5][5];
	for(i=0; i<5; ++i)
		for (j = 0; j < 5; ++j) {
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j]) {
				p = i;
				q = j;
			}
		}
	printf("%d\n", abs(p - 3+1) + abs(q - 3+1));
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