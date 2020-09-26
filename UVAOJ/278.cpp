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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Case, row, col;
	char ch;
	cin >> Case;
	while (Case--) {
		cin >> ch >> row >> col;
		if (ch == 'r' || ch == 'Q') {
			// rook or queen
			cout << min(row, col) << '\n';
		} else if (ch == 'k') {
			// knight
			cout << ((row + 1) / 2) * ((col + 1) / 2) + (row / 2) * (col / 2) << '\n';
		}  else {
			// king
			cout << ((row + 1) / 2) * ((col + 1) / 2) << '\n';
		}
	}
}