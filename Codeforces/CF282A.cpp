#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	string str;
	x = 0;
	cin >> n;
	for (; n; --n) {
		cin >> str;
		if (str[1] == '-' || str[0] == '-')
			--x;
		else if (str[0] == '+' || str[1] == '+')
			++x;
	}

	printf("%d\n", x);

	return 0;
}