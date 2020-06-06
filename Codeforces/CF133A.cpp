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
	int A[126 - 33 + 1] = {};
	string S;
	cin >> S;
	for (i = 0; i < S.length(); ++i)
		++A[S[i] - 33];
	if (A['H' - 33] || A['Q' - 33] || A['9' - 33])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}