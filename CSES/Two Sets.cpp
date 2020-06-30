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
#include <numeric>
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

#define EPS 1e-9
#define N 500005
#define PIXEL 1024
#define ll long long
#define pi pair<ll, ll>

using namespace std;

inline void newline() { cout << '\n'; }
inline void split(vector<string>& vect, string& str, char delim) {
	string each;
	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != delim)
			each.push_back(*it);
		else {
			vect.push_back(each);
			each.clear();
		}
	}
	if (each.size()) vect.push_back(each);
}

inline bool sort_pred(const pair<int, int>& left, const pair<int, int>& right) {
	return left.first < right.first;
}

inline bool lb_pred(const pair<int, int>& left, int right) {
	return left.first < right;
}

int P[N], Q[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int  n, setSize, lo, hi, pSize, qSize;
	scanf("%d", &n);
	setSize = n/2;
	if (setSize == 0 ||(setSize%2 && n%2==0) || (setSize%2==0 && n%2)) cout << "NO\n";
	else {
		pSize = qSize = 0;
		for (lo = setSize, hi = setSize + 1; lo > 0; --lo, ++hi) {
			if (pSize < setSize) {
				P[pSize++] = lo;
				P[pSize++] = hi;
			}
			else {
				Q[qSize++] = lo;
				Q[qSize++] = hi;
			}
		}

		if (n&1) {
			if (pSize < qSize) P[pSize++] = hi;
			else Q[qSize++] = hi;
		}
		puts("YES");
		printf("%d\n%d", pSize, P[0]);
		for (int i = 1; i < pSize; ++i)
			printf(" %d", P[i]);
		puts("");
		printf("%d\n%d", qSize, Q[0]);
		for (int i = 1; i < qSize; ++i)
			printf(" %d", Q[i]);
		puts("");
	}
}