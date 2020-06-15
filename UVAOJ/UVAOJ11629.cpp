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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define EPS 1e-2
#define N 30001
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline bool _equal(double x, double y) {
	return abs(x - y) < EPS;
}

inline bool _more(double x, double y) {
	return (x - y) > EPS;
}

inline bool _less(double x, double y) {
	return (x - y) < -EPS;
}
void tokenize(string& s, vector<string>& vect) {
	string tok;
	for (auto i = s.begin(); i != s.end(); ++i) {
		if (*i != ' ')
			tok.push_back(*i);
		else if(tok.size()){
			vect.push_back(tok);
			tok.clear();
		}
	}

	if (tok.size())
		vect.push_back(tok);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p, g, G;
	string line;
	double amt;
	unordered_map<string, double> table;
	cin >> p >> g;
	getline(cin, line);
	while (p) {
		getline(cin, line);
		vector<string> vect;
		tokenize(line, vect);
		table[vect[0]] = stod(vect[1]);
		--p;
	}

	G = 1;
	while (g) {
		getline(cin, line);
		vector<string> vect;
		tokenize(line, vect);
		amt = 0.0;
		for (int i = 0; i < (int)vect.size() - 2; ++i) {
			if (vect[i][0] != '+') {
				auto it = table.find(vect[i]);
				amt = amt + it->second;
			}
		}
		
		double actual = stod(vect[vect.size() - 1]);
		string comp = vect[vect.size() - 2];
		int ans;

		if (comp == ">") {
			// cout << "greater?\n";
			ans = _more(amt, actual);
		} else if (comp == "<") {
			ans = _less(amt, actual);
		} else if (comp == ">=") {
			ans =_more(amt, actual) || _equal(amt, actual);
		} else if (comp == "<=") {
			ans = _less(amt, actual) || _equal(amt, actual);
		} else {
			ans = _equal(amt, actual);
		}
		if (ans) {
			cout << "Guess #" << G << " was correct.\n";
		} else {
			cout << "Guess #" << G << " was incorrect.\n";
		}
		--g;
		++G;
	}


}
