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

int is_prime(int n) {
	if (n <= 3)
		return n > 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	for (int i = 5; i * i <= n; i+=6)
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	scanf("%d%d", &n, &m);
	for (i = n + 1; !is_prime(i); ++i);
	if (i == m)
		printf("YES\n");
	else
		printf("NO\n");

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