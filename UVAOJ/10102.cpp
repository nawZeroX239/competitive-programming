#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
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
using namespace std;
#define N 20000
#define EPS 1e-9

pair<int, int> u[N];
pair<int, int> v[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int n;
	while (cin >> n) {
		int m, o;
		m = o = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < n; ++j) {
				if (s[j] == '1') {
					u[m].first = i;
					u[m++].second = j;
				}
				if (s[j] == '3') {
					v[o].first = i;
					v[o++].second = j;
				}
			}
		}
		//cout << "o:" << o << " m:" << m << '\n';
		int global = INT_MIN;
		for (int i = 0; i < m; ++i) {
			int local = INT_MAX;
			for (int j = 0; j < o; ++j) {
				local = min(local, abs(u[i].first - v[j].first) + abs(u[i].second - v[j].second));
			}
			global = max(global, local);
		}
		cout << global << '\n';
	}
}