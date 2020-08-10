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

const int N = 10000;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, o, p, r, s;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cin >> m;
		sort(arr, arr + n);
		r = s = -1;
		for (int i = 0; i < n - 1; ++i) {
			o = m - arr[i];
			if (binary_search(arr, arr+n, o)) {
				p = lower_bound(arr, arr + n, o) - arr;
				if (p == i && arr[i + 1] != o)
					continue;
				if (r == -1 && s == -1) {
					r = arr[i];
					s = o;
				} else {
					if (abs(o - arr[i]) < abs(r - s)) {
						r = arr[i];
						s = o;
					}
				}
			}
		}

		cout << "Peter should buy books whose prices are " << r << " and " << s << "." << '\n';
		cout << '\n';
	}
}
