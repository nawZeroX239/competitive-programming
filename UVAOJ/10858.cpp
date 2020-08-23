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

vector<int> factors;
vector<vector<int>> vvi;

void recur(int n, int k) {
	for (int i = k; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			factors.push_back(i);
			recur(n/i, i);
			factors.pop_back();
		}
	}
	if (factors.size()) {
		factors.push_back(n);
		vvi.push_back(factors);
		factors.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	while (cin >> n) {
		if (n == 0) break;
		factors.clear();
		vvi.clear();
		recur(n, 2);
		cout << vvi.size() << '\n';
		for (int i = 0; i < vvi.size(); ++i) {
			cout << vvi[i][0];
			for (int j = 1; j < vvi[i].size(); ++j) {
				cout << ' ' << vvi[i][j];
			}
			cout << '\n';
		}
	}
}
