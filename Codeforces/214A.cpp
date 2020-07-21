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

#define N 100

#define EPS 1e-9
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int sol = 0;
	for (int b = 0; b <= n; ++b) {
		int a = n - b;
		double x = sqrt(a);
		// cout <<"x:"<< x << " a:"<<a<<'\n';
		if (abs(x - floor(x)) < EPS && ((int)x + b * b) == m) {
			// cout << "|b:" << b << " a:" <<a << '\n';
			++sol;
		}
	}
	cout << sol << '\n';
}