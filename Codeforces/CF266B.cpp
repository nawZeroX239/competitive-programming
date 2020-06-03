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
	cin >> n >> t >> line;
	while (t) {

		for(i=1; i<n; )
		if (line[i - 1] == 'B' && line[i] == 'G') {
			swap(line[i - 1], line[i]);
			i = i += 2;
		} else
			++i;

		--t;
	}
	cout << line;
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