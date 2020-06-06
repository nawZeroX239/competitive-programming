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
	int B[4];
	int a, b, c, d, e, f, i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;
	cin >> B[0] >> B[1] >> B[2] >> B[3] >> d;
	c = 0;
	for (i = 1; i <= d; ++i)
		if (i % B[0] == 0 || i % B[1] == 0 || i % B[2] == 0 || i % B[3] == 0)
			++c;

	
	cout << c << '\n';
}
