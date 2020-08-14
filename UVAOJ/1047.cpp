#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <iomanip>
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
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int N = 20;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}


int n, m, best, sum, cnt, arr[N];
vector<int> ans, quant;
vector<vector<int>> shared;

bool used[N];

void recur(int k, int sz) {
	
	if (sz == m) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i]) sum += arr[i];
		}

		for (int i = 0; i < shared.size(); ++i) {
			cnt = 0;
			for (int j = 0; j < shared[i].size(); ++j) {
				if (used[shared[i][j]]) {
					++cnt;
				}
				if (cnt > 1) {
					sum -= quant[i];
					--cnt;
				}
			}
		}

		if (best < sum) {
			ans.clear();
			for (int i = 0; i < n; ++i) {
				if (used[i]) ans.push_back(i + 1);
			}
			best = sum;
		}
		return;
	}

	for (int i = k; i < n; ++i) {
		used[i] = true;
		recur(i + 1, sz + 1);
		used[i] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, l, tc;


	tc = 1;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cin >> k;

		shared.resize(k);
		quant.resize(k);

		for (int i = 0; i < k; ++i) {
			cin >> l;
			shared[i].resize(l);
			for (int j = 0; j < l; ++j) {
				cin >> shared[i][j];
				--shared[i][j];
			}
			cin >> quant[i];
		}

		best = INT_MIN;
		recur(0, 0);
		cout << "Case Number  " << tc << '\n';
		cout <<"Number of Customers: "<< best << '\n';
		cout << "Locations recommended:";
		for (int i = 0; i < m; ++i) {
			cout << ' ' << ans[i];
		}
		cout << "\n\n";
		++tc;
	}

}