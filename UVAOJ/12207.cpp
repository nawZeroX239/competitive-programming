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
	
	int n, p, c, tc = 1;
	char ch;

	while (cin >> p >> c) {
		if (p == 0 && c == 0) break;
		list<int> li;
		for (int i = 1; i <= min(p, 1000); ++i) {
			li.push_back(i);
		}
		cout << "Case " << tc++ << ':' << '\n';
		while (c--) {
			cin >> ch;
			if (ch == 'N') {
				n = li.front();
				cout << li.front() << '\n';
				li.push_back(n);
				li.pop_front();
			} else {
				cin >> n;
				li.remove(n);
				li.push_front(n);
			}
		}
	}
}
