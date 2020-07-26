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

#define N 1e5
#define EPS 1e-9

long long arr[(int)N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long lim = 1e18, ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	ans = 1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			ans = 0;
			break;
		}

		if (ans > lim/arr[i]) {
			ans = -1;
			break;
		}

		ans *= arr[i];
	}

	cout << ans << '\n';
}
