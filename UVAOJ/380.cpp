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
const int N = 10000;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

struct e {
	int start, end, tar;
};

int o, t, ret;
unordered_map<int, vector<e>> mp;
bool vis[N];
e pro;

int recur(int k) {
	// cout << k << '\n';

	if (vis[k]) return 9999;
	vis[k] = true;
	for (int i = 0; i < mp[k].size(); ++i) {
		if (t>= mp[k][i].start && t <= mp[k][i].end) {
			ret = recur(mp[k][i].tar);
			vis[k] = false;
			return ret;
		}
	}
	vis[k] = false;
	return k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, start, d, u, v;
	cin >> tc;

	cout << "CALL FORWARDING OUTPUT" << '\n';

	for (int id = 1; id <= tc; ++id) {

		mp.clear();

		while (cin >> u) {
			if (u == 0) break;
			cin >> start >> d >> v;
			pro.start = start;
			pro.end = start + d;
			pro.tar = v;
			mp[u].push_back(pro);
		}


		cout << "SYSTEM " << id << '\n';
		while (cin >> t) {
			if (t == 9000) break;
			cin >> o;
			// memset(vis, 0, sizeof vis);
			cout << "AT " <<setw(4)<<setfill('0')<< t << " CALL TO " << setw(4) << setfill('0')<< o << " RINGS " <<setw(4)<<setfill('0')<<recur(o) << '\n';

		}
	}

	cout << "END OF OUTPUT" << '\n';
}