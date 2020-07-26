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

#define N 6
#define EPS 1e-9


int g[N][N];
int n, m, k;

int solve() {
	int sol = 0;
	int blk;
	for (int i = 0; i <= (1 << n) - 1; ++i) {
		for (int j = 0; j <= (1 << m) - 1; ++j) {
			blk = 0;
			for (int r = 0; r < n; ++r) {
				if ((1 << r) & i) continue;
				
				for (int c = 0; c < m; ++c) {
					if ((1 << c) & j) continue;
					blk += g[r][c];
				}
			}
			if (blk == k)
				++sol;
		}
	}

	return sol;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ins;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> ins;
		for (int j = 0; j < m; ++j)
			g[i][j] = (ins[j] == '#' ? 1 : 0);
	}
	
	cout << solve() << '\n';

}
