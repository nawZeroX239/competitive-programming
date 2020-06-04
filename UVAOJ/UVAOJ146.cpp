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
	string line;
	char a[100];
	int c;
	while (cin >> line) {
		if (line[0] == '#')
			break;

		n = line.length();
		for (i = 0; i < n; ++i)
			a[i] = line[i];
		next_permutation(a, a + n);
		r = 0;
		for (i = 1; i < n && !r; ++i)
			if (line[i] > line[i - 1])
				r = 1;
		a[n] = '\0';
		if (r)
			printf("%s\n", a);
		else
			printf("No Successor\n");

	}


	return 0;
}
