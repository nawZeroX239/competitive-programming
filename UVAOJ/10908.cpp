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
int r, c, n, m;

int solve() {
	int rd = 1;
	while (true) {
		for (int i = r - rd; i <= r + rd; ++i) {
			if (i < 0 || i >= n || c + rd > m || c - rd < 0) 
				goto label;
			if (grid[i][c + rd] != grid[r][c])
				goto label;
			if (grid[i][c - rd] != grid[r][c])
				goto label;
		}


		for (int i = c - rd; i <= c + rd; ++i) {
			if (i < 0 || i >= m || r - rd < 0 || r + rd >= n)
				goto label;

			if (grid[r - rd][i] != grid[r][c])
				goto label;
			if (grid[r + rd][i] != grid[r][c])
				goto label;
		}

		++rd;
	}

label:
	return 2*(rd-1) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc, q;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> q;
		grid.clear();
		grid.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> grid[i];
		cout << n << ' ' << m << ' ' << q << '\n';
		while (q--) {
			cin >> r >> c;
			cout << solve() << '\n';
		}
	}

}