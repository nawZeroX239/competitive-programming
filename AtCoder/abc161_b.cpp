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
const int N = 100;
const long double EPS = 1e-9;
using namespace std;
template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int arr[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, total, nc;
	cin >> n >> m;
	total = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		total += arr[i];
	}
	double lim = (double)total / (4 * m);
	nc = 0;
	for (int i = 0; i < n; ++i) {
		nc += (arr[i]-lim>=0);
	}
	if (nc >= m)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}