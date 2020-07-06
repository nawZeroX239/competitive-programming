#include <algorithm>
#include <array>
#include <bitset>
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

#define EPS 1e-100
#define N 100000
#define ll long long
#define pi pair<ll, ll>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dim, ans, idx, n;
	while (cin >> dim) {
		n = pow(2, dim);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		ans = -1;

		for (int i = 0; i < n; ++i) {
			int self = 0;
			for (int j = 0; j < dim; ++j) {
				self = self + v[i^(1 << j)];
			}

			for (int j = 0; j < dim; ++j) {
				int u = 0;
				int x = i ^ (1 << j);
				for (int k = 0; k < dim; ++k) {
					u = u + v[x ^ (1 << k)];
				}
				ans = max(ans, u + self);
			}

		}
		cout << ans << '\n';
	}

}
