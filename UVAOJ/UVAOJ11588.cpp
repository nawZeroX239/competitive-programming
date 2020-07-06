#include <algorithm>
#include <array>
#include <bitset>
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

#define EPS 1e-2
#define N ('Z' - 'A' + 1)
#define ll long long
#define pi pair<ll, ll>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, r, c, m, n, _max, idx, ans;
	string s;
	cin >> x;
	for (int t = 1; t <= x; ++t) {
		int freq[N] = {};
		cin >> r >> c >> m >> n;
		_max = -1;
		for (int i = 0; i < r; ++i) {
			cin >> s;
			for (auto it = s.begin(); it != s.end(); ++it) {
				idx = *it - 'A';
				++freq[idx];
				_max = max(_max, freq[idx]);
			}
		}
		ans = 0;
		for (int i = 0; i < N; ++i)
			if (freq[i] == _max)
				ans = ans + freq[i] * m;
			else
				ans = ans + freq[i] * n;
		cout << "Case " << t << ": " << ans << '\n';
		
	}
}
