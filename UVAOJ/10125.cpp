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

#define N 1000
#define EPS 1e-9

int n, arr[N];

int solve() {
	int ans = INT_MIN;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int sum = arr[i] + arr[j] + arr[k];
				int pos = lower_bound(arr, arr + n, sum) - arr;
				if (pos<n && arr[pos]-sum == 0&& pos-i && pos-j && pos-k) {
					// cout << arr[i] << " + " << arr[j] << " + " << arr[k] << " : " << pos << '\n';
					ans = max(ans, sum);
				}
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n);
		int ans = solve();

		if (ans == INT_MIN) cout << "no solution" << '\n';
		else cout << ans << '\n';
	}


}