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
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;

	for (i = 0; i < s1.length() && !ans; ++i) {
		if (tolower(s1[i]) > tolower(s2[i]))
			ans = 1;
		else if (tolower(s1[i]) < tolower(s2[i]))
			ans = -1;
	}

	printf("%d\n", ans);

	return 0;
}