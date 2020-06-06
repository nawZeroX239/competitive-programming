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

	int i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;
	scanf("%d", &n);
	long p = 0;
	for (i = 0; i < n; ++i) {
		scanf("%d", &m);
		p = p + m;
	}
	cout << ((double)p/ n) << '\n';
	
}
