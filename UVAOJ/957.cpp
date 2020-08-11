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
const int N = 100000;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int arr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, yr, lo, hi, xk, yk, alo, ahi;
	while (cin >>yr>>n) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		alo = ahi = -1;
		xk = INT_MIN;
		for (int i = 0; i < n; ++i) {
			lo = arr[i];
			hi = arr[i] + yr;
			int j = i;
			yk = 0;
			while (j < n && arr[j] < hi) {
				++j;
				++yk;
			}

			if (xk < yk) {
				xk = yk;
				alo = arr[i];
				ahi = arr[max(0, j-1)];
			}
		}

		cout << xk << ' ' << alo << ' ' << ahi << '\n';
	}
	
}