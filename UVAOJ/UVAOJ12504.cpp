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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int _case;
	cin >> _case;
	string line;
	getline(cin, line);
	for (int T = 0; T < _case; ++T) {
		set<string> add, remove, update;
		unordered_map<string, string> dict;
		getline(cin, line);
		int n = line.length();
		for (int i = 1; i < n - 1; ++i) {
			string key, value;
			while (line[i] != ':') {
				key.push_back(line[i]);
				++i;
			}
			++i;
			while (i<n-1 && line[i] != ',') {
				value.push_back(line[i]);
				++i;
			}
			dict[key] = value;
		}
		getline(cin, line);
		//for (auto it = dict.begin(); it != dict.end(); ++it) {
		//	cout << it->first << " " << it->second << '\n';
		//}
		int eq = 1;
		n = line.length();
		for (int i = 1; i < n - 1; ++i) {
			string key, value;
			while (line[i] != ':') {
				key.push_back(line[i]);
				++i;
			}
			++i;
			while (i < n-1 && line[i] != ',') {
				value.push_back(line[i]);
				++i;
			}
			auto it = dict.find(key);
			// cout << "new [" << key << ", " << value+"]" << '\n';
			if (it == dict.end()) {
				add.insert(key);
			} else if (it->second != value) {
				update.insert(key);
				dict.erase(it);
			} else {
				dict.erase(it);
			}
		}

		for (auto it = dict.begin(); it != dict.end(); ++it)
			remove.insert(it->first);
		auto it1 = add.begin();
		auto it2 = remove.begin();
		auto it3 = update.begin();
		if (it1 == add.end() && it2 == remove.end() && it3 == update.end()) {
			cout << "No changes\n" << '\n';
			continue;
		}
		if (it1 != add.end()) {
			cout << "+" + *it1;
			++it1;
		}
		while (it1 != add.end()) {
			cout << "," + *it1;
			++it1;
		}
		if(add.size()) cout << '\n';

		if (it2 != remove.end()) {
			cout << "-" + *it2;
			++it2;
		}
		while (it2 != remove.end()) {
			cout << "," + *it2;
			++it2;
		}
		if(remove.size()) cout << '\n';
		
		if (it3 != update.end()) {
			cout << "*" + *it3;
			++it3;
		}
		while (it3 != update.end()) {
			cout << ","+*it3;
			++it3;
		}

		if(update.size()) cout << '\n';
		cout << '\n';

	}
}
