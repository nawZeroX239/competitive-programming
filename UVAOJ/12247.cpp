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

	int a, b, c, x, y;
	while (cin >> a >> b >> c >> x >> y) {
		bool used[54] = {};
		int cards[6];
		if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0) {
			break;
		}
		used[a] = used[b] = used[c] = used[x] = used[y] = true;
		cards[0] = next_card(a, b, c, x, y);
		cards[1] = next_card(a, c, b, x, y);
		cards[2] = next_card(c, a, b, x, y);
		cards[3] = next_card(c, b, a, x, y);
		cards[4] = next_card(b, c, a, x, y);
		cards[5] = next_card(b, a, c, x, y);
		sort(cards, cards + 6);
		int card = cards[5];
		if (cards[0] == -1) {
			cout << -1 << '\n';
		} else {
			while (used[card]) {
				++card;
			}
			if (card > 52) {
				cout << -1 << '\n';
			} else {
				cout << card << '\n';
			}
		}
	}
}