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
	int c[50] = {};
	
	cin >> n>>line;
	c[0] = 1;
	for (i = 1, j = 1; i < line.length(); ++i)
		if (line[i - 1] == line[i])
			c[j-1] = c[j-1]+1;
		else
			c[j++] = 1;
	r = 0;
	for (int i = 0; i < j; ++i)
		if (c[i] > 1)
			r = r + c[i] - 1;

	printf("%d\n", r);
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