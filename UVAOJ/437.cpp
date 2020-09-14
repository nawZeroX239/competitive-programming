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

bool comp(const tuple<int, int, int>& left, const tuple<int, int, int>& right) {
	int x1 = get<0>(left), y1 = get<1>(left), z1 = get<2>(left);
	int x2 = get<0>(right), y2 = get<2>(right), z2 = get<2>(right);

	if (x1 < x2) return true;
	if (x1 == x2 && y1 < y2) return true;
	if (x1 == x2 && y1 == y2 && z1 < z2) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, x, y, z, tc = 1;
	int ans;
	while (cin >> n) {
		if (n == 0) break;
		vector<tuple<int, int, int>> blocks;
		for (int i = 0; i < n; ++i) {
			cin >> x>>y>>z;
			blocks.push_back(make_tuple(x, y, z));
			blocks.push_back(make_tuple(y, x, z));
			blocks.push_back(make_tuple(z, x, y));
			blocks.push_back(make_tuple(x, z, y));
			blocks.push_back(make_tuple(y, z, x));
			blocks.push_back(make_tuple(z, y, x));
		}
		n = blocks.size();
		sort(blocks.begin(), blocks.end());
		vector<int> lis(n, 0);
		ans = -1;
		for (int i = 0; i < n; ++i) {
			lis[i] = get<2>(blocks[i]);
			// cout << get<0>(blocks[i])<< ' ' << get<1>(blocks[i]) <<' '<<get<2>(blocks[i]) << '\n';
			for (int j = 0; j < i; ++j) {
				if (get<0>(blocks[i]) > get<0>(blocks[j])
					&& get<1>(blocks[i]) > get<1>(blocks[j])) {
					lis[i] = max(lis[i], lis[j] + get<2>(blocks[i]));
				}
			}
			ans = max(ans, lis[i]);
		}
		cout << "Case " << tc++ << ": maximum height = " << ans << '\n';
	}

	return 0;
}
