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

#define N 50
#define EPS 1e-9

using namespace std;

int Q[N][4];
vector<vector<int>> S;
vector<int> s;
int m, n;

void backtrack(int k) {
	if (s.size() == n) {
		S.push_back(s);
		return;
	}

	for (int i = k; i <= m; ++i) {
		s.push_back(i);
		backtrack(i);
		s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q;
	long long ans, best;

	cin >> n >> m >> q;
	
	backtrack(1);

	// cout << S.size() << '\n';

	for (int i = 0; i < q; ++i) {
		cin>>Q[i][0]>>Q[i][1]>>Q[i][2]>>Q[i][3];
	}

	ans = 0;
	for (int i = 0; i < S.size(); ++i) {
//		for (int k = 0; k < S[i].size(); ++k)
//			cout << S[i][k] << ' ';
//		cout << '\n';
		best = 0;
		for (int j = 0; j < q; ++j) {
			if (S[i][Q[j][1] - 1] - S[i][Q[j][0] - 1] == Q[j][2])
				best += Q[j][3];
		}
		ans = max(ans, best);
	}
	cout << ans << '\n';
}