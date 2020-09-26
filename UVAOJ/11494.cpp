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
#define EPS 1e-9
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

int next_card(int a, int b, int c, int x, int y) {
	if (x < a && y < b) {
		return -1;
	} else if (x > a && y > b) {
		return 1;
	}

	return c + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
			break;
		}
		// cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ';
		if (x1 == x2 && y1 == y2) {
			cout << 0 << '\n';
		} else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1- y2)) {
			cout << 1 << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
}