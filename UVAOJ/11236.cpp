#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
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
using namespace std;

#define N 2000
#define EPS 1e-9
double step = 0.01;

bool eq(double l, double r) {
	return abs(l - r) < EPS;
}

// beautiful idea from redgreencode
void solve() {
	long long a, b, c, d, e, f;
	long long n = 2e9, m = 1e6;

	for (a = 1; a <= N; ++a) {
		if (a * a * a * a > n) break;
		for (b = a; a <= N - a; ++b) {
			if (a * b * b * b > n) break;
			for (c = b; c <= N - a - b; ++c) {
				e = a * b * c;
				f = a + b + c;
				if (e*c > n) break;

				if (e <= m || (f * m)%(e - m) ) continue;
				d = (f * m) / (e - m);

				if (c > d || e * d > n || f+d > N) continue;
				printf("%.2lf %.2lf %.2lf %.2lf\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
