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

int n, m, dp[10205][100];
pair<int, int> pi[100] ;

int recur(int s, int k) {
	if (k == n) {
		if ((s > 2000 && s <= m + 200) || s <= m) return 0;
		return -500;
	}
	if (dp[s][k] != -1) return dp[s][k];
	int bes = -500, s1 = s + pi[k].first;
	if (s1 <= m + 200) {
		bes = max(bes, pi[k].second + recur(s1, k + 1));
	}
	bes = max(bes, recur(s, k + 1));
	return dp[s][k] = bes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (cin >> m >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> pi[i].first >>pi[i].second;
		}
		memset(dp, -1, sizeof dp);
		cout << recur(0, 0) << '\n';
	}

}