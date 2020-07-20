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
#define N 200000
#define EPS 1e-9

int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, ans, w, sum, lo, hi;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	ans = lo = 0; hi = n - 1;
	while (lo <= hi) {
		w = arr[hi--];
		if (hi >= 0 && arr[hi] + w <= k) {
			--hi;
			++ans;
			continue;
		}

		if (lo < hi && arr[lo] + w <= k)
			++lo;
	
		++ans;
	}
	cout << ans << '\n';
}
