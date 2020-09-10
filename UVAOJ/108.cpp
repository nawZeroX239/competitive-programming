#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const long double EPS = 1e-9;
const int N = 105;

using namespace std;

int ar[N][N];
int n;
int solve() {
	int m, ret=-128, sum;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> m;
			ar[i][j] = m + ar[i - 1][j] + ar[i][j - 1] - ar[i - 1][j - 1];
		}
	}

	for (int x1 = 1; x1 <= n; ++x1) {
		for (int y1 = 1; y1 <= n; ++y1) {
			for (int x2 = x1; x2 <= n; ++x2) {
				for (int y2 = y1; y2 <= n; ++y2) {
					ret = max(ret, ar[x2][y2] + ar[x1 - 1][y1 - 1] - ar[x2][y1 - 1] - ar[x1 - 1][y2]);
				}
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << solve() << '\n';
}