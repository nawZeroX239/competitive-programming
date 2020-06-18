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
#define N 30001
#define ll long long
#define pi pair<ll, ll>
using namespace std;

void output(int s, int a) {
	cout << "(Street: " << s << ", " << "Avenue: " << a << ")\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, s, f, minX, minY, cacul;
	cin >> n;
	while (n) {
		cin >> a >> s >> f;
		vector<int> x(f), y(f);
		for (int i = 0; i < f; ++i)
			cin >> x[i] >> y[i];
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		cacul = f / 2;
		if (f & 1) {
			minX = x[cacul];
			minY = y[cacul];
		} else {
			minX= min(x[cacul], x[cacul - 1]);
			minY = min(y[cacul], y[cacul - 1]);
		}
		output(minX, minY);
		--n;
	}
}
 