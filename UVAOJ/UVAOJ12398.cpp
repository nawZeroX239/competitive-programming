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
	string s;
	int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
	t = 1;
	while (getline(cin, s)) {
		int a[10][10] = {};
		if (s.length() > 0)
		for (k = s.length()-1; k >=0; --k) {
			if (s[k] == 'a') {
				i = 1;
				j = 1;
			} else if (s[k] == 'b') {
				i = 1;
				j = 2;
			} else if (s[k] == 'c') {
				i = 1;
				j = 3;
			} else if (s[k] == 'd') {
				i = 2;
				j = 1;
			} else if (s[k] == 'e') {
				i = 2;
				j = 2;
			} else if (s[k] == 'f') {
				i = 2;
				j = 3;
			} else if (s[k] == 'g') {
				i = 3;
				j = 1;
			} else if (s[k] == 'h') {
				i = 3;
				j = 2;
			} else {
				i = 3;
				j = 3;
			}
			a[i][j] = (a[i][j] + 1) % 10;
			if (i + 1 <= 3)
				a[i + 1][j] = (a[i + 1][j] + 1) % 10;
			if (i - 1 >= 1)
				a[i - 1][j] = (a[i - 1][j] + 1) % 10;
			if (j + 1 <= 3)
				a[i][j + 1] = (a[i][j + 1] + 1) % 10;
			if (j - 1 >= 1)
				a[i][j - 1] = (a[i][j - 1] + 1) % 10;

		}

		printf("Case #%d:\n", t);
		for (i = 1; i <= 3; ++i) {
			printf("%d %d %d\n", a[i][1], a[i][2], a[i][3]);
		}
		++t;
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