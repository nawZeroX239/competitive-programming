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
	int _case, n, d, time;
	string topic;

	cin >> _case;
	for (int T = 1; T <= _case; ++T) {
		cin >> n;
		unordered_map<string, int> table;

		while (n) {
			cin >> topic >> time;
			table[topic] = time;
			--n;
		}

		cin >> d>>topic;
		auto it = table.find(topic);
		cout << "Case " << T;
		if (it != table.end() && it->second <= d + 5) {
			if (it->second <= d)
				cout << ": Yesss" << '\n';
			else
				cout << ": Late" << '\n';
		} else {
			cout << ": Do your own homework!" << '\n';
		}
	}
}
