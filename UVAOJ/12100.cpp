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

int toInt(string& s) {
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc, n, m, x, w;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		list<pair<int, int>> li;
		pair<int, int> e;
		list<pair<int, int>>::iterator it, next;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			li.push_back(make_pair(i, x));
		}
		int ans = 0;
		while (true) {
			w = -1;
			for (it = li.begin(); it != li.end(); ++it) {
				w = max(w, it->second);
			}
				it = li.begin();
				if (it->second == w) {
					if (it->first == m) {
						break;
					}
					++ans;
				} else {
					li.push_back(*it);
				}
				li.pop_front();

		}
		cout << ans+1<< '\n';
	}
}
