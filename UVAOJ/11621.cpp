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
const int N = 2147483647;
template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

vector<long long> vll;

void prep() {
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 32; ++j) {
			vll.push_back(pow(2, i) * pow(3, j));
		}
	}

	sort(vll.begin(), vll.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long m;
	prep();
	while (cin >> m) {
		if (m == 0) break;
		cout << *(lower_bound(vll.begin(), vll.end(), m)) << '\n';
	}
}