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

const int N = 1e5;
const long double EPS = 1e-9;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, out;
	scanf("%d%d", &n, &m);

	multiset<int> S;
	multiset<int>::iterator it;
	while(n--){
		scanf("%d", &x);
		S.insert(x);
	}

	while (m--) {
		scanf("%d", &x);
		it = S.lower_bound(x);
		if (it == S.end()) {
			if (S.size()) {
				--it;
				out = *it;
				S.erase(it);
			} else {
				out = -1;
			}
		} else {
			if (*it > x) {
				if (it == S.begin()) {
					out = -1;
				} else {
					--it;
					out = *it;
					S.erase(it);
				}
			} else {
				out = *it;
				S.erase(it);
			}
		}
		printf("%d\n", out);
	}
}