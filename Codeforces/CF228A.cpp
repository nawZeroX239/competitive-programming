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
	long A[4] = {};
	int ans = 0;
	cin >> A[0] >> A[1] >> A[2] >> A[3];
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 4 && A[i] != A[j]; ++j);
		if (j >= 4)
			++ans;
	}

	printf("%d\n", 4 - ans);
}
