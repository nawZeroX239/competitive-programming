#include <iostream>
#include <string>
#include <sstream>
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
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 1005;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

int arr[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n, m, a, b, A, B,t0, t1, t;
	bool side;
	cin >> T;
	while (T--) {
		cin >> n;
		stringstream ss;

		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}

		arr[0] = 0;
		sort(arr, arr+n+1);

		m = n, t = 0;
		while (m >= 4) {
			A = arr[1],  B = arr[2];
			a = arr[m], b = arr[m-1];
			t0 = 2 * A + a + b;
			t1 = 2 * B + A + a;
			if (t0 < t1) {
				ss << A << ' ' << a<<'\n';
				ss << A << '\n';
				ss << A << ' '<< b << '\n';
				ss << A << '\n';
				t += t0;
			} else {
				ss << A << ' ' << B << '\n';
				ss << A << '\n';
				ss << b << ' ' << a << '\n';
				ss << B << '\n';
				t += t1;
			}
			m -= 2;
		}

		if (m == 1) {
			t += arr[m];
			ss << arr[m] << '\n';
		} else if(m == 2){
			t += arr[m];
			ss << arr[m - 1] << ' ' << arr[m] << '\n';
		} else if (m == 3) {
			t += arr[m-2] + arr[m-1] + arr[m];
			ss << arr[m-2] << ' ' << arr[m-1] << '\n';
			ss << arr[m-2] << '\n';
			ss << arr[m - 2] << ' ' << arr[m] << '\n';
		}
		cout << t << '\n';
		cout << ss.str();
		if (T) cout << '\n';
	}
}