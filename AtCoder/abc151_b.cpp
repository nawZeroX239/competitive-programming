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
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const int N = 2*1e5;

template <class T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, m, sum, x, w;
	cin >> n >> k >> m;
	sum = 0;
	for (int i = 1; i < n; ++i) {
		cin >> x;
		sum += x;
	}
	
	w = n * m - sum;
	if (w < 0 && sum/n >= m) {
		cout << 0 << '\n';
	} else if (w >= 0 && w<=k) {
		cout << w << '\n';
	} else {
		cout << -1 << '\n';
	}
}
		