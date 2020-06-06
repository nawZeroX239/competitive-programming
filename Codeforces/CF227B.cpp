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
	int A[(int)1e5] = {}, B[(int)1e5] = {};
	long long L, R;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> x;
		A[x - 1] = i+1;
		B[x - 1] = n - i;
	}

	L = R = 0;
	cin >> m;
	for (i = 0; i < m; ++i) {
		cin >> x;
		L += A[x - 1];
		R += B[x - 1];
	}
	cout << L << ' ' << R << '\n';

	return 0;
}