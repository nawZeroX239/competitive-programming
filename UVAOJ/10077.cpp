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

const int N = 1048576;
const long double EPS = 1e-9;

using namespace std;

template <class T>
T gcd(T a, T b) 
{
	if (b == 0) return a;
	return gcd(b, a % b);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int ln, lm, sn, sm, rn, rm;

	while (cin >> n >> m) {
		if (n == 1 && m == 1) break;
		sn = sm = 1;
		ln = rm = 0;
		lm = rn = 1;
		while (true) {
			if (sn == n && sm == m)
				break;
			if (n*sm > m*sn) {
				cout << "R";
				ln = sn;
				lm = sm;
				sn += rn;
				sm += rm;
			} else {
				cout << "L";
				rn = sn;
				rm = sm;
				sn += ln;
				sm += lm;
			}
		}
		cout << '\n';
	}
}