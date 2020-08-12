#include <iostream>
#include <string>
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
const int N = 1000001;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

vector<int> vi;

int nod(int n) {
	int ret = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			ret += 2;
			if (n / i == i) --ret;
		}
	}

	return ret;
}

void prep() {
	int n = 1, m;
	vi.push_back(1);
	while (n <= N) {
		m = n + nod(n);
		// cout << m << '\n';
		vi.push_back(m);
		n = m;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;
	prep();

	cin >> T;
	for (int tc = 1; tc<=T; ++tc) {
		cin >> a >> b;
		auto it1 = lower_bound(vi.begin(), vi.end(), a);
		auto it2 = lower_bound(vi.begin(), vi.end(), b);
		cout << "Case " << tc << ": ";
		if(it1 != vi.end() && *it1 == a && it2 != vi.end() && *it2 == b) {
			cout<< it2 - it1 + 1 << '\n';
		} else {
			if(*it2 == b) cout <<it2 - it1 + 1<< '\n';
			else cout << it2 - it1 << '\n';
		}
		
	}
}