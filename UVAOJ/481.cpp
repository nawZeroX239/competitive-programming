#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
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
#include <climits>
#include <cmath>
#include <bitset>
#include <numeric>
using namespace std;

const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 100;

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
	return left.second > right.second;
}

bool lb_pred(const pair<int, int>& left, const int right) {
	return left.first < right;
}


vector<int> p, vi;

void print_LIS(int i) {
	if (p[i] == -1) {
		cout << vi[i] << '\n';
		return;
	}
	print_LIS(p[i]);
	cout << vi[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int var, k, pos, n, lis_end;
	while (cin >> var) {
		vi.push_back(var);
	}
	n = vi.size();
	vector<int> L(n, 0), L_id(n, 0);
	p.assign(n, -1);
	lis_end = k = 0;

	for (int i = 0; i < n; ++i) {
		pos = lower_bound(L.begin(), L.begin() + k, vi[i]) - L.begin();
		L[pos] = vi[i];
		L_id[pos] = i;

		p[i] = pos ? L_id[pos - 1] : -1;
		if (pos == k) {
			k = pos + 1;
			lis_end = i;
		}
	}
	cout << k << '\n';
	cout << '-' << '\n';
	print_LIS(lis_end);

	return 0;
}