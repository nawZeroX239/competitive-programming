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

#define N 20
#define EPS 1e-9

int T[N][N + 1], R[N][N + 1], H[N][N + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, tc, ans;
	cin >> tc;
	for (int TC = 1; TC <= tc; ++TC) {
		cin >> n >> m;
		vector<string> grid(n);
		for (int i = 0; i < n; ++i)
			cin >> grid[i];
		ans = INT_MAX;
		bool sol;

		for (int c = 0; c < m; ++c) {
			int nc=0;
			bool sol = true;
			for (int r = 0; r < n; ++r) {
				int k, l;
				if (grid[r][c] == '0') {
					continue;
				}

				for (k = c - 1; k >= 0; --k) {
					if (grid[r][k] == '0') {
						break;
					}
				}
				sol = k >= 0;
				for (l = c + 1; l < m; ++l) {
					if (grid[r][l] == '0') {
						break;
					}
				}
				
				sol = k>=0 ||  l < m;
				if (!sol) break;
				nc += min((k>=0 ? c -k : INT_MAX), (l < m ? l - c : INT_MAX));
			}

			if (sol) {
				ans = min(ans, nc);
			}
		}
		cout << "Case " << TC << ": " << (ans == INT_MAX ? -1 : ans) << '\n';
	}


}