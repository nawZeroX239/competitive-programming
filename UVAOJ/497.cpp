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
#define INF 999999999
#define  EPS 1e-9
#define N  10000


using namespace std;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}
int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

vector<int> vi, p, dp;

int LIS(int i) {

	if (dp[i] != -1) return dp[i];
	int bes = 1;
	for (int j = 0; j < i; ++j) {
		if (vi[i] > vi[j]) {
			int temp = 1 + LIS(j);
			if (bes < temp) {
				p[i] = j;
				bes = temp;
			}
		}
	}
	return dp[i] = bes;
}

void print_ans(int i) {
	if (p[i] == -1) return;
	print_ans(p[i]);
	cout << vi[p[i]] << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int tc, n;
	getline(cin, s);
	tc = toInt(s);
	getline(cin, s);

	while (tc--) {
		vi.clear();
		while (getline(cin, s)) {
			if (s.length() == 0) break;
			vi.push_back(toInt(s));
		}

		vi.push_back(INF);
		n = vi.size();
		p.resize(n); dp.resize(n);
		for (int i = 0; i < n; ++i) p[i] = dp[i] = -1;
		cout <<"Max hits: "<<LIS(n - 1)-1 << '\n';
		print_ans(n - 1);
		if (tc > 0) cout << '\n';
	}

}