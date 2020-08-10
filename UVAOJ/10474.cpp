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
const int N = 10000;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, x, tc, k;
	tc = 1;
	while (cin >> n >> q) {
		if (n == 0 && q == 0) break;
		cout << "CASE# " << tc << ":" << '\n';
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		sort(arr.begin(), arr.end());

		while(q--) {
			cin >> x;
			auto it = lower_bound(arr.begin(), arr.end(), x);
			if (it != arr.end() && *it == x) {
				k =it - arr.begin() + 1;
				cout << x << " found at " << k << '\n';
			} else {
				cout << x << " not found" << '\n';
			}
		}

		++tc;
	}
}