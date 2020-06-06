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
int e, f, i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b, c;
	int d['Z' - 'A' + 1] = {};
	cin >> a >> b >> c;
	for (i = 0; i < a.length(); ++i)
		++d[a[i] - 'A'];
	for (i = 0; i < b.length(); ++i)
		++d[b[i] - 'A'];
	for (i = 0; i < c.length(); ++i)
		--d[c[i] - 'A'];
	for (i = 0; i < 'Z' - 'A' + 1; ++i)
		if (d[i])
			break;
	if (i >= 'Z' - 'A' + 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
