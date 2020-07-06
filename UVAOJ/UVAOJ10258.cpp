#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct contestant {
	int field[3] = {};
	int ctr[10] = {};
	int solve[10] = {};
};

struct comp {
	inline bool operator() (const contestant& a, const contestant& b) {
		
		if (a.field[1] == b.field[1] && a.field[2] == b.field[2])
			return a.field[0] < b.field[0];
		if (a.field[1] == b.field[1])
			return a.field[2] < b.field[2];
		return a.field[1] > b.field[1];
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	int c, q, t;
	char L;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	while (n) {
		int k = 0;
		vector<contestant> vect;
		
		while (getline(cin, s)) {
			if (s.length() == 0)
				break;
			stringstream ss(s);
			ss >> c >> q >> t >> L;
			// cout << c << ' ' << q << ' ' << t << ' ' << L << '\n';
			int idx;
			for (idx = 0; idx < vect.size() && vect[idx].field[0] != c; ++idx);
			if (idx >= vect.size()) {
				contestant cc;
				cc.field[0] = c;
				vect.push_back(cc);
			}

			if (vect[idx].solve[q])
				continue;
			if (L == 'C' || L == 'I') {
				// cout << "idx " << idx << '\n';
				if (L == 'C') {
					++vect[idx].field[1];
					vect[idx].field[2] += t;
					if (vect[idx].ctr[q])
						vect[idx].field[2] +=vect[idx].ctr[q] * 20;
					vect[idx].solve[q] = 1;
				} else {
					++vect[idx].ctr[q];
					// vect[idx].field[2] += 20;
				}
			} else {

			}

		}
		sort(vect.begin(), vect.end(), comp());
		for (int i = 0; i < vect.size(); ++i)
			cout << vect[i].field[0] << ' ' << vect[i].field[1] << ' ' << vect[i].field[2] << '\n';
		--n;
		if (n)
			cout << '\n';
	}

}