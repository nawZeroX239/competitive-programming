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

#define EPS 1e-2
#define N 1000001
#define ll long long
#define pi pair<ll, ll>
using namespace std;

int arr[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(&arr[0], &arr[0] + n);
		int mid = n / 2;
		x = 1;
		if (n & 1) {
			for (int lo = mid - 1; lo >= 0 && arr[lo] == arr[mid]; --lo)
				++x;
			for(int hi = mid + 1; hi < n && arr[hi] == arr[mid]; ++hi)
				++x;
			cout << arr[mid] << ' '<<x << ' '<< 1 << '\n';
		} else {
			for (int lo = mid - 1; lo >= 0 && arr[lo] >= arr[mid - 1] && arr[lo] <= arr[mid]; --lo)
				++x;
			for (int hi = mid + 1; hi < n && arr[hi] >= arr[mid - 1] && arr[hi] <= arr[mid]; ++hi)
				++x;
			cout << arr[mid - 1] << ' ' << x << ' '<< arr[mid] - arr[mid - 1] + 1<<'\n';
		}
	}
}
 