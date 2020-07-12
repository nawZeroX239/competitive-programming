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

#define N 20
using namespace std;

#define EPS 1e-9
int arr[N+1];
int v, v0;

double func(double x) {
	return x * 0.3 * sqrt((v - (double)v0 * x)/x);
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	double c;
	while (cin >> v >> v0) {
		if (v + v0 == 0) break;
		double best = 0.0;
		int y = 1;
		bool unique = true;
		for (x = 1; (c=func(x)) > EPS; ++x) {
			// cout <<"x:"<<x<< " c:" << c << '\n';
			if (c>best && c-best>EPS) {
				best = c;
				y = x;
				unique = true;
			} else if (best-c < EPS) unique = false;

			if (c - best < 0) break;
		}
		if (unique && v > v0) cout << y << '\n';
		else cout << 0 << '\n';
	}

}