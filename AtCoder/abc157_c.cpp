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
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const int N = 3;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int digit[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, k, n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	
	for (int i = 0; i < m; ++i) {
		cin >> k >> d;
		adj[k - 1].push_back(d);
	}

	for (int i = (n - 1 == 0 ? 0: pow(10, n-1)); i < pow(10, n); ++i) {
		int tmp = i;
		for (int j = 0; j < n; ++j) {
			digit[j] = tmp % 10;
			tmp /= 10;
		}
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < adj[j].size(); ++l) {
				ok = ok && adj[j][l] == digit[n -j -1];
			}
		}
		if (ok) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
}
