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
	int n, m;
	string key, value, nul;
	unordered_map<string, string> table;
	cin >> n;
	getline(cin, nul);

	while(n) {
		getline(cin, key);
		getline(cin, value);
		table[key] = value;
		--n;
	}

	cin >> m;
	getline(cin, nul);
	while (m) {
		getline(cin, key);
		auto it = table.find(key);
		cout << it->second << '\n';
		--m;
	}
}
