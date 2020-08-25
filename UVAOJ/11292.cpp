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
const int N = 20000;

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

bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}
	return left.first < right.first;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}

int d[N], h[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, c;
	bool ok;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> h[i];
		}
		sort(d, d + n);
		sort(h, h + m);
		ok = true, c = 0;
		for (int i = 0, j=0; i < n; ++i) {
			while (j < m && h[j] < d[i]) {
				++j;
			}
			if (j >= m) {
				ok = false;
				break;
			}
		
			c += h[j++];
		}

		if (ok) {
			cout << c << '\n';
		} else {
			cout << "Loowater is doomed!" << '\n';
		}
	}

}