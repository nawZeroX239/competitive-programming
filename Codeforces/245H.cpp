#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
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

#define INF 1e9
#define  EPS 1e-9
#define N 5005
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

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

int dp[N][N];
bool isPalin[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto t1 = chrono::high_resolution_clock::now();

	string s;
	int q, start, end, n;
	cin >> s >> q;
	n = s.length();
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
		isPalin[i][i] = 1;
		isPalin[i + 1][i] = 1;
	}

	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i+len<= n; ++i) {
			isPalin[i][i + len - 1] = isPalin[i + 1][i + len - 2] && (s[i] == s[i + len - 1]);
			dp[i][i + len - 1] = isPalin[i][i + len - 1] + dp[i + 1][i + len - 1] + dp[i][i + len - 2] - dp[i + 1][i + len - 2];
		}
	}
	while (q--) {
		cin >> start >> end;
		cout << dp[start-1][end-1] << '\n';
	}


	auto t2 = chrono::high_resolution_clock::now();
	double dt = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() / 1000.0;
	
	//cout << dt << 's' << '\n';

	return 0;
}