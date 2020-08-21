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
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 3;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int sum, r, c;
bool u[N][N], v[N][N];

bool pred() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (u[i][j]) return false;
		}
	}

	return true;
}

int recur() {

	if (pred()) return -1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			sum = 0;
			for (int k = 0; k < 4; ++k) {
				r = i + cy[k], c = j + cx[k];
				if (r >=0 && r <= 2 && c>=0 && c <= 2) {
					sum += u[r][c];
				}
			}
			v[i][j] = sum % 2;
		}
	}

	memcpy(u, v, sizeof v);
	return 1 + recur();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	string s;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < N; ++i) {
			cin >> s;
			for (int j = 0; j < N; ++j) {
				u[i][j] = s[j] - '0';
			}
		}
		
		cout << recur() << '\n';
	}
}
