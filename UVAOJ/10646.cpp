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
string st[52];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, y, pos, val, Case = 1;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 52; ++i) {
			cin >> st[i];
		}
		y = 0, pos = 26;
		for (int step = 0; step < 3; ++step) {
			if (st[pos][0] >= '2' && st[pos][0] <= '9') {
				val = st[pos][0] - '0';
			} else {
				val = 10;
			}
			// cout << "pos: " << pos << "val: " << val << ' ' << b[pos] << '\n';

			y += val;
			pos = pos - (10 - val) - 1;
		}
		if (y-1 > pos) {
			cout << "Case " << Case++ << ": " << st[26 + (y - pos - 1)] << '\n';

			//for (int i = 27; i < 52; ++i, ++z) {
			//	if (z == y - 1) {
			//		cout << "Case " << Case++ << ": " << st[i] << '\n';
			//		break;
			//	}
			//}

		} else {
			cout << "Case " << Case++ << ": " << st[y-1] << '\n';
			/*for (int i = 0; i <= pos; ++i) {
				if (i == y - 1) {
					cout <<"Case "<<Case++<<": "<< st[i] << '\n';
					break;
				}
			}*/
		}
	}
}