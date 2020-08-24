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
const int N = 1000;

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

struct e {
	int a, b, c;
};
e arr[N];
bool pred(e& left, e& right) {
	int f = left.a * right.b, g = right.a * left.b;
	if (f == g) return left.c < right.c;
	return f < g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].a >> arr[i].b;
			arr[i].c = i + 1;
		}
		sort(arr, arr + n, pred);
		cout << arr[0].c;
		for (int i = 1; i < n; ++i) {
			cout <<' '<< arr[i].c;
		}
		cout << '\n';
		if (T) cout << '\n';
	}
}