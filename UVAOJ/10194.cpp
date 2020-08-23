#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
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
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;

const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int cx[] = { -1, 1, 0, 0 }, cy[] = { 0, 0, -1, 1 };
const int N = 52;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

struct e {
	int win, lose, tie;
	int plus, minus;
	string s, comp;
};

e foo;

int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}

bool pred(e& left, e& right) {
	int x, y;
	x = left.win * 3 + left.tie, y = right.win * 3 + right.tie;
	if (x != y) {
		return x > y;
	}
	x = left.win, y = right.win;
	if (x != y) {
		return x > y;
	}
	
	x = left.plus - left.minus;
	y = right.plus - right.minus;
	if (x != y) {
		return x > y;
	}

	x = left.plus, y = right.plus;
	if (x != y) {
		return x > y;
	}

	x = left.win + left.lose + left.tie;
	y = right.win + right.lose + right.tie;
	if (x != y) {
		return x < y;
	}

	return left.comp < right.comp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc, n, m, x, y, a, b;
	string s, t, lc, title;
	getline(cin, s);
	tc = toInt(s);
	while (tc--) {
		unordered_map<string, e> mp;
		unordered_map<string, e>::iterator u, v;
		vector<e> ve;

		getline(cin, title);
		getline(cin, s);
		n = toInt(s);
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			foo.s = s;
			lc.clear();
			for (int i = 0; i < s.length(); ++i) {
				lc.push_back(tolower(s[i]));
			}
			foo.comp = lc;
			mp[s] = foo;
		}

		getline(cin, s);
		m = toInt(s);
		for (int i = 0; i < m; ++i) {
			vector<string> toks;
			getline(cin, s);
			t.clear();
			for (int i = 0; i < s.length(); ++i) {
				if (s[i] == '#' || s[i] == '@') {
					toks.push_back(t);
					t.clear();
				} else {
					t.push_back(s[i]);
				}
			}
			toks.push_back(t);


			x = toInt(toks[1]), y = toInt(toks[2]);
			if (x - y) {
				a = x > y;
				b = x < y;
				mp[toks[0]].win += a;
				mp[toks[0]].lose += b;
				mp[toks[3]].win += b;
				mp[toks[3]].lose += a;
			} else {
				++mp[toks[0]].tie;
				++mp[toks[3]].tie;
			}

			mp[toks[0]].plus += x;
			mp[toks[0]].minus += y;
			mp[toks[3]].plus +=  y;
			mp[toks[3]].minus += x;
			// cout << toks[0] <<' '<< toks[1] <<' '<< toks[2] <<' '<< toks[3] << '\n';
		}

		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ve.push_back(it->second);
		}

		sort(ve.begin(), ve.end(), pred);
		cout << title << '\n';
		for (int i = 0; i < ve.size(); ++i) {
			//[a]) Team name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
			cout << i + 1 << ") " << ve[i].s << ' ' << (ve[i].win * 3 + ve[i].tie) << "p, " << (ve[i].win + ve[i].tie + ve[i].lose) <<
				"g (" << ve[i].win << '-' << ve[i].tie << '-' << ve[i].lose << "), " << (ve[i].plus - ve[i].minus) << "gd (" <<
				ve[i].plus << '-' << ve[i].minus << ')' << '\n';
		}
		if (tc) cout << '\n';
	}

}
