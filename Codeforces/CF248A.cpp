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
	int ans = 0;
	scanf("%d", &n);
	for (r =l =i = 0; i < n; ++i) {
		scanf("%d%d",&a, &b);
		l += a;
		r += b;
	}
	
	if (l > n / 2)
		ans = ans + (n - l);
	else
		ans = ans + l;
	if (r > n / 2)
		ans = ans + (n - r);
	else
		ans = ans + r;
	printf("%d\n", ans);

	
}
