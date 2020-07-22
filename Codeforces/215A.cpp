
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

#define N 50

#define EPS 1e-9
using namespace std;

int a[N], b[N];

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	int best = INT_MIN;
	int nc = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (b[j] % a[i] == 0) {
				if (b[j] / a[i] > best) {
					nc = 1;
					best = b[j] / a[i];
				}
				else if (b[j] / a[i] == best) {
					++nc;
				}
			}
	cout << nc << '\n';

}