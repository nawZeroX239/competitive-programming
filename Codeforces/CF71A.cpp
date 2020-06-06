#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
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

using namespace std;
int a, b, c, d, e, f, i, j, k, l, m, n, o, q, r, s, t, u, v, w, x, y, z;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> n;
	while (n) {
		cin >> S;
		if (S.length() > 10) {
			cout << S[0] << S.length() - 2 << S[S.length() - 1] << '\n';
		} else {
			cout << S << '\n';
		}

		--n;
	}
}
