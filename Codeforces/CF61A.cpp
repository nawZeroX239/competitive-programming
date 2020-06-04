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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	string s1, s2;
	cin >> s1 >> s2;
	for (i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[i])
			s1[i] = '1';
		else
			s1[i] = '0';
	}
	cout << s1;

	return 0;
}
