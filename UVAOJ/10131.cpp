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

const long double EPS = 1e-9;
const int N = 1005;

using namespace std;

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

struct e {
	int a, b, c;
};

int memo[N];
e ar[N];
vector<vector<int>> sol(N);
inline bool comp(const e& left, const e&right) {
	return left.b > right.b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, idx, k;
	n = 0;
	while (cin >> ar[n].a >> ar[n].b) {
		++n;
		ar[n - 1].c = n;
	}

	sort(ar, ar + n, comp);
	for (int i = 0; i < n; ++i) {
		sol[i].push_back(ar[i].c);
		memo[i] = 1;
	}
	
	idx = 0;
	for (int i = 1; i < n; ++i) {
		k = -1;
		for (int j = 0; j < i; ++j) {
			if (ar[j].b != ar[i].b && ar[j].a < ar[i].a && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
				k = j;
			}
		}
		if (k != -1) {
			sol[i].assign(sol[k].begin(), sol[k].end());
			sol[i].push_back(ar[i].c);
		}
		if (memo[i] > memo[idx]) {
			idx = i;
		}
	}
	cout << memo[idx] << '\n';
	for (int i = 0; i < memo[idx]; ++i) {
		cout << sol[idx][i] << '\n';
	}
	
}