#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
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
#include <climits>
#include <bitset>
using namespace std;

#define N (int)1e5
#define EPS 1e-9

vector<string> grid;

bool isRect(int r, int c, int n, int m) {
	for (; r < n; ++r)
		for (int j = c; j < m; ++j)
			if (grid[r][j] != '1')
				return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	while (cin >> n) {
		if (n == 0) break;
		cin >> m;
		grid.clear();
		grid.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> grid[i];
		int ans = 0;
		// making all poissble (x, y), (x1, y1)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int ii = i; ii < n; ++ii)
					for (int jj = j; jj < m; ++jj)
						if (isRect(i, j, ii + 1, jj + 1))
							++ans;
		cout << ans << '\n';
	}
}