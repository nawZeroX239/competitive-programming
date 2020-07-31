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
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const int N = 1e5+5;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x, y, m;
	cin >> n;
	vector<int> p(n), q(n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
		arr[i] = i + 1;
	}
	
	x = y = -1;
	m = 1;
	do {
		if (x == -1 && arr == p) {
			x = m;
		}

		if (y == -1 && arr == q) {
			y = m;
		}

		if (x > 0 && y > 0)
			break;
		++m;
	} while (next_permutation(arr.begin(), arr.end()));

	cout << abs(x - y) << '\n';
}
		