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
int a, b, c, d, e, f, i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans, a, b;
	scanf("%d%d", &n, &c);
	a = b = c;
	ans = 0;
	while (n) {
		scanf("%d", &c);
		if (c<a || c>b)
			++ans;

		a = min(a, c);
		b = max(b, c);
		--n;
	}

	printf("%d\n", ans);
}
