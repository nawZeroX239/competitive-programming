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
	int a[100];
	scanf("%d", &n);
	p = INT_MIN;
	q = INT_MAX;
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		p = max(p, a[i]);
		q = min(q, a[i]);
	}
	for (i = 0; a[i] != p; ++i);
	for (j = n-1; a[j] != q; --j);

	printf("%d\n", i>j ? i + n - j-2 : i+n-j-1);

}
