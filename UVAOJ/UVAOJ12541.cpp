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

#define EPS 1e-100
#define N 100000
#define ll long long
#define pi pair<ll, ll>

using namespace std;

bool comparator(int& a, int& b) { return a > b; }

struct thingy {
	string s;
	int d, m, y;
};

bool pred(thingy& _this, thingy& _other) {
	if (_this.y-_other.y)
		return _this.y < _other.y;
	if (_this.m-_other.m)
		return _this.m < _other.m;

	return _this.d < _other.d;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<thingy> things(n);
	for (int i = 0; i < n; ++i) 
		cin >> things[i].s >> things[i].d >> things[i].m >> things[i].y;
	sort(things.begin(), things.end(), pred);
	// for (auto it = things.begin(); it != things.end(); ++it)
	//	cout << it->s << ' ' << it->d << ' ' << it->m << ' ' << it->y << '\n';
	
	if (n > 1) {
		cout <<things[n-1].s << '\n';
		cout << things[0].s << '\n';
	} else {
		cout << things[0].s << '\n';
		cout << things[0].s << '\n';
	}
}
