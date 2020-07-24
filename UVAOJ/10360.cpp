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

#define N 1025
#define M 20000
#define EPS 1e-9

int kills[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, n, m, d, x, y, best;
	cin >> tc;
	while (tc--) {
		// memset(kills, 0, sizeof kills);
		cin >> d >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y>>m;
			for (int i = max(0, x - d); i <= min(x + d, N - 1); ++i)
				for (int j = max(0, y - d); j <= min(y + d, N - 1); ++j)
					kills[i][j] += m;

		}
		best =  x = y = -1;
		for(int i=0; i<N; ++i)
			for (int j = 0; j < N; ++j) {
				if (kills[i][j] > best) {
					x = i; y = j;
					best = kills[i][j];
				}
				kills[i][j] = 0;
			}
		cout << x << ' ' << y << ' ' << best << '\n';
	}

}
