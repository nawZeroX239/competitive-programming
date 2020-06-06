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
	int ans = 0;
	cin >> n;
	
	while (n) {
		cin >> a >> b >> c;
		ans = ans + (a + b + c > 1);
		--n;
	}
	printf("%d\n", ans);
	return 0;
}