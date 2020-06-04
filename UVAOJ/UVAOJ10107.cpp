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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	long long a[10000];
	for (n = 0; scanf("%lld", &a[n]) == 1; ++n);
	for (i = 0; i < n; ++i) {
		j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			swap(a[j], a[j - 1]);
			--j;
		}
		if ((i + 1) & 1)
			printf("%lld\n", a[(i + 1) / 2]);
		else
			printf("%lld\n", (a[i / 2] + a[i / 2 + 1]) / 2);

	}
	return 0;
}
