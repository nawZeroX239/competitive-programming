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

#define N 12
#define EPS 1e-9
#define PI 3.14159265358979323846264338327950

int g[N][N];
int price[N];
int level[N];
int n, m, x;

int solve() {
	int ans = INT_MAX;
	int cost, ok;
	for (int i = 1; i <= (1 << n) - 1; ++i) {
		cost = 0;
		memset(level, 0, sizeof level);
		for (int k = 0; k < n; ++k) {
			if ((i>>k) & 1) {
				cost += price[k];
				for (int l = 0; l < m; ++l) {
					level[l] += g[k][l];
				}
			}
		}
		
		ok = true;
		for (int k = 0; k < m; ++k)
			ok = ok && level[k] >= x;
		if (ok) {
			ans = min(ans, cost);
		}
	}

	return ans == INT_MAX ? -1 : ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];
	}
	cout << solve() << '\n';
}
