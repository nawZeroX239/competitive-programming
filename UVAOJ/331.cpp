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

#define EPS 1e-9
#define N 5

using namespace std;
int arr[N], n;
int ans;
void backtrack() {
	if (is_sorted(arr, arr + n)) {
		++ans;
		return;
	}

	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			backtrack();
			swap(arr[i], arr[i + 1]);
		}
	}
}

int main() {
	int tc = 1;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		ans = 0;
		if (is_sorted(arr, arr + n)) {
			cout << "There are " << ans << " swap maps for input data set " << tc << ".\n";
		} else {
			backtrack();
			cout << "There are " << ans << " swap maps for input data set " << tc << ".\n";
		}
		++tc;
	}
}
