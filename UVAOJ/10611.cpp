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

const int N = 50000;
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

	int n, m, q, k, l;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> q;
	while (q--) {
		cin >> m;
		k = lower_bound(arr, arr+n, m) - arr;
		if (k < n) {
			if (arr[k] == m) {
				l = upper_bound(arr, arr + n, m) - arr;
				if (k - 1 >= 0 && l < n) {
					cout << arr[k - 1] << ' ' << arr[l] << '\n';
				} else if (l < n) {
					cout << "X " << arr[l] << '\n';
				} else {
					cout << arr[k - 1] << " X" << '\n';
				}
			} else {
				l = k - 1;
				while (l >= 0 && arr[k] == arr[l]) {
					l--;
				}
					
				if (l >= 0) {
					cout << arr[l] << ' ' << arr[k] << '\n';
				}else  {
					cout << "X " << arr[k] << '\n';
				}

			}
		} else {
			cout << arr[n - 1] <<" X" << '\n';
		}
	}
}