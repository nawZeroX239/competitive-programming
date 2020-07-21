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

#define N 100

#define EPS 1e-9
using namespace std;

int arr[N];
int main() {
	int n, m, ans;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	ans = 0;
	for (int i = 0; i < n && i < m; ++i) {
		if (arr[i] < 0) {
			ans += arr[i] * -1;
		}
	}
	cout << ans << '\n';
}