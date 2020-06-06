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
	int ans;
	int A[] = { 1, 2, 3, 4, 5 };
	cin >> n;
	for (s = i = 0; i < n; ++i) {
		cin >> m;
		s += m;
	}

	ans = 0;
	n = n + 1;
	for (i=0; i < 5; ++i)
		if ((s + A[i]-1) % n)
			++ans;

	printf("%d\n", ans);

	return 0;
}