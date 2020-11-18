#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define INF 1e9
#define  EPS 1e-9
#define N 200001
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

// translation
int tx[] = { 0, 0, 1, -1 };
int ty[] = { -1, 1, 0, 0 };

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int toInt(string& s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, arr[N], prefix[N], ctr;
	char ch;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}	
	ctr = 0;
	prefix[arr[0]] = ctr;
	for (int i = 1; i < n; ++i) {
		cin >> ch;
		if (ch == '0') ++ctr;
		prefix[arr[i]] = ctr;
	}
	//cout << ctr << '\n';

	for (int i = 2; i <= n; ++i) {
		if (prefix[i] < prefix[i - 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}